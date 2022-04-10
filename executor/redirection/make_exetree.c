/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_exetree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:54:46 by mypark            #+#    #+#             */
/*   Updated: 2022/04/11 01:31:55 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"
#include "parse_tree.h"
#include "utils.h"
#include "redirection.h"
#include <fcntl.h>
#include <signal.h>
#include "info.h"

static enum e_exetree_node	to_enum_exetree_node(enum e_parsetree_node type)
{
	if (type == NODE_AND)
		return (EXE_AND);
	if (type == NODE_OR)
		return (EXE_OR);
	if (type == NODE_PIPE)
		return (EXE_PIPE);
	return (EXE_REDIR);
}

t_exetree_node	*make_exetree_node(\
	t_exetree_node *parent, \
	t_parsetree_node *p_nd, \
	t_exe_info *info\
)
{
	t_exetree_node	*e_nd;

	e_nd = new_exetree_node(parent, to_enum_exetree_node(p_nd->type), 0, 1);
	if (p_nd->type & (NODE_AND | NODE_OR))
	{
		e_nd->left = make_exetree_node(e_nd, p_nd->left, info);
		e_nd->right = make_exetree_node(e_nd, p_nd->right, info);
	}
	else if (p_nd->type == TOKENS)
		make_cmd(p_nd, e_nd, info);
	else if (p_nd->type == NODE_PIPE)
		make_exe_pipe(p_nd, e_nd, info);
	else if (p_nd->type & (NODE_IRD | NODE_ORD | NODE_ARD | NODE_HRD))
		make_exe_redir(p_nd, e_nd, info);
	return (e_nd);
}

t_exetree_node	*make_exetree(t_parsetree_node *p_nd, t_exe_info *info)
{
	t_exetree_node	*e_nd;

	e_nd = make_exetree_node(NULL, p_nd, info);
	return (e_nd);
}
