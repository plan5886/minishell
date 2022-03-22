/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:38:17 by mypark            #+#    #+#             */
/*   Updated: 2022/03/23 00:52:01 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_utils.h"
#include "test.h"

int	parse_bool(t_parsetree_node *pt_node)
{
	t_tokens		*tks;
	t_token			*tk;
	t_tokens_node	*curr;
	t_tokens		*l_tks;
	t_tokens		*r_tks;

	tks = pt_node->tokens;
	curr = tks->tail;
	curr = pass_parenthesis_forward(curr);
	while (curr != tks->head)
	{
		tk = curr->content;
		if (tk->type == AND || tk->type == OR)
		{
			r_tks = cut_tokens_back(tks, curr);
			l_tks = cut_tokens_front(tks, curr);
			pt_node->right = new_parsetree_node(r_tks, pt_node);
			pt_node->left = new_parsetree_node(l_tks, pt_node);
			pt_node->parsed = 1;
			return (1);
		}
		curr = curr->prev;
		curr = pass_parenthesis_forward(curr);
	}
	return (0);
}