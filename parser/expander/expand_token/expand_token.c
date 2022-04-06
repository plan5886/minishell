/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:14:52 by mypark            #+#    #+#             */
/*   Updated: 2022/04/06 22:28:53 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "expander.h"
#include "info.h"

t_tokens	*expand_token_env(t_token *tk, t_exe_info *info)
{
	t_tokens	*tks;

	tks = new_tokens();
	env_expander(tks, tk->content, info);
	free_token(tk);
	return (tks);
}

t_tokens	*expand_token_wildcard(t_token *tk, t_exe_info *info)
{
	t_tokens	*tks;

	info++;
	tks = new_tokens();
	wildcard_expander(tks, tk);
	if (tks->head == NULL)
		tks->push_tail(tks, tk);
	else
		free_token(tk);
	return (tks);
}

t_tokens	*expand_token_quote(t_token *tk, t_exe_info *info)
{
	t_tokens	*tks;

	info++;
	tks = new_tokens();
	quote_remover(tks, tk);
	free_token(tk);
	return (tks);
}
