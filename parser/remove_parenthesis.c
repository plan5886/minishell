/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_parenthesis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:31:39 by mypark            #+#    #+#             */
/*   Updated: 2022/03/23 01:56:32 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_utils.h"
#include "test.h"

void	remove_parenthesis(t_parsetree_node *pt_node)
{
	t_token		*first;
	t_token		*last;
	t_token		*tk;
	t_tokens	*tks;

	tks = pt_node->tokens;
	first = tks->head->content;
	last = tks->tail->content;
	if (first->type == LPT && last->type == RPT)
	{
		tk = tks->pop_head(tks);
		free_token(tk);
		tk = tks->pop_tail(tks);
		free_token(tk);
	}
}