/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:38:17 by mypark            #+#    #+#             */
/*   Updated: 2022/03/21 15:29:49 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_tree.h"

int	parse_pipe(t_parsetree_node *pt_node)
{
	t_tokens		*tks;
	t_token			*tk;
	t_tokens_node	*curr;
	t_tokens		*l_tks;
	t_tokens		*r_tks;

	tks = pt_node->tokens;
	curr = tks->tail;
	while (curr != tks->head)
	{
		pass_parenthesis(curr);
		tk = curr->content;
		if (tk->type == PIPE)
		{
			syntax_error_check(curr);
			r_tks = cut_tokens_back(tks, curr);
			l_tks = cut_tokens_front(tks, curr);
			pt_node->right = new_parsetree_node(r_tks, pt_node);
			pt_node->left = new_parsetree_node(l_tks, pt_node);
			pt_node->parsed = 1;
			return (1);
		}
		curr = curr->prev;
	}
	syntax_error_check(tks->head);
	return (0);
}
