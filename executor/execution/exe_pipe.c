/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 23:46:16 by mypark            #+#    #+#             */
/*   Updated: 2022/04/04 01:04:22 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"
#include "info.h"
#include "executor.h"
#include "strict.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "test.h"

static void	exe_pipe_child(\
	t_exetree_node *child, \
	enum e_exetree_node type, \
	int *fd, \
	t_exe_info *info\
)
{
	pid_t	pid;

	if (type == EXE_PIPE)
		execute_node(child, fd[0], fd[1], info);
	else
	{
		pid = strict_fork();
		if (pid)
			insert_new_pid(info, pid);
		else
		{
			execute_node(child, fd[0], fd[1], info);
			exit(0);
		}
	}
}

static void	wait_childs(t_exe_info *info)
{
	t_list	*pids;
	t_list	*poped;
	int		pid;
	int		ws;

	pids = info->pids;
	while(pids)
	{
		poped = ft_lstpop_front(&pids);
		pid = ((int *)poped->content)[0];
		waitpid(pid, &ws, 0);
		insert_new_exit(info, calc_exit_status(ws));
		ft_lstdelone(poped, free);
	}
	info->pids = NULL;
}

void	exe_pipe(t_exetree_node *exe_node, int parent_infd, int parent_outfd, t_exe_info *info)
{
	int		p[2];
	int		fd[3];
	int		*exit_status;
	t_list	*last;

	set_exe_node_fd(exe_node, parent_infd, parent_outfd);
	close_pipe_oneside(exe_node->parent, exe_node, info);
	pipe(p);
	insert_new_pipe(info, p);
	fd[0] = exe_node->infd;
	fd[1] = p[1];
	exe_pipe_child(exe_node->left, exe_node->left->type, fd, info);
	fd[0] = p[0];
	fd[1] = exe_node->outfd;
	exe_pipe_child(exe_node->right, exe_node->right->type, fd, info);
	if (exe_node->parent == NULL || exe_node->parent->type != EXE_PIPE)
	{
		close_pipes(info->pipes);
		wait_childs(info);
		last = ft_lstlast(info->exits);
		exit_status = last->content;
		exit(*exit_status);
	}
}