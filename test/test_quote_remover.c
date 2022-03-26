/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_quote_remover.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:23:28 by mypark            #+#    #+#             */
/*   Updated: 2022/03/26 18:52:48 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <readline/readline.h>
#include <sys/wait.h>

int	main(int argc, char **argv, char **envp)
{
	t_tokens			*tks;
	t_parsetree_node	*pt_head;
	char				*input;
	int					cnt;
	pid_t				pid;
	int					exit_status;

	while (1)
	{
		cnt = 0;
		tks = new_tokens();
		input = readline("msh ^ㅁ^/ $$ ");
		if (input[0] == '\0')
			continue;
		pid = fork();
		if (pid == 0)
		{
			tokenizer(tks, input);
			print_tokens(tks);
			syntax_error_check(tks);
			pt_head = parse_script(tks);
			print_parsetree(pt_head, &cnt);
			expand_env(pt_head, envp);
			print_parsetree(pt_head, &cnt);
			expand_wildcard(pt_head, envp);
			print_parsetree(pt_head, &cnt);
			remove_quote(pt_head, envp);
			// print_parsetree(pt_head, &cnt);
			//free_parsetree(pt_head);
		}
		else
			waitpid(pid, &exit_status, 0);
		free_tokens(tks);
		free(input);
	}
}