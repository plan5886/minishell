/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:52:29 by mypark            #+#    #+#             */
/*   Updated: 2022/04/11 01:34:42 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer_actions.h"
#include "token.h"
#include "utils.h"
#include "error.h"
#include "libft.h"
#include "strict.h"

enum e_token	to_enum_token(char *str)
{
	if (ft_strncmp(str, "<", -1) == 0)
		return (TK_IRD);
	if (ft_strncmp(str, ">", -1) == 0)
		return (TK_ORD);
	if (ft_strncmp(str, "<<", -1) == 0)
		return (TK_HRD);
	if (ft_strncmp(str, ">>", -1) == 0)
		return (TK_ARD);
	if (ft_strncmp(str, "|", -1) == 0)
		return (TK_PIPE);
	if (ft_strncmp(str, "&&", -1) == 0)
		return (TK_AND);
	if (ft_strncmp(str, "||", -1) == 0)
		return (TK_OR);
	if (ft_strncmp(str, "(", -1) == 0)
		return (TK_LPT);
	if (ft_strncmp(str, ")", -1) == 0)
		return (TK_RPT);
	if (ft_strncmp(str, "&", -1) == 0)
		return (TK_INVALID);
	return (TK_STR);
}

static void	tokenizer_blank(t_tokenizer *tokenizer, char input)
{
	if (is_blank(input))
		tokenizer->state = T_BLANK;
	else
	{
		push_buffer(tokenizer->buf, input);
		if (is_meta(input))
			tokenizer->state = T_SINGLE_META;
		else if (input == '\'')
			tokenizer->state = T_SINGLE_QUOTE;
		else if (input == '\"')
			tokenizer->state = T_DOUBLE_QUOTE;
		else
			tokenizer->state = T_CHARS;
	}
}

void	init_tokenizer(t_tokenizer *tknizr, t_tokens *tks)
{
	tknizr->state = T_BLANK;
	tknizr->buf = strict_malloc(sizeof(t_buffer), 1);
	init_buffer(tknizr->buf);
	tknizr->actions[0] = tokenizer_blank;
	tknizr->actions[1] = tokenizer_chars;
	tknizr->actions[2] = tokenizer_single_quote;
	tknizr->actions[3] = tokenizer_double_quote;
	tknizr->actions[4] = tokenizer_single_meta;
	tknizr->actions[5] = tokenizer_double_meta;
	tknizr->tokens = tks;
}

void	reset_tokenizer(t_tokenizer *tknizr)
{
	reset_buffer(tknizr->buf);
	free(tknizr->buf);
}

void	tokenizer(t_tokens *tks, char *str)
{
	t_tokenizer			tokenizer;

	init_tokenizer(&tokenizer, tks);
	while (*str)
	{
		tokenizer.actions[tokenizer.state](&tokenizer, *str);
		str++;
	}
	if (tokenizer.buf->len)
		issue_token(tokenizer.tokens, tokenizer.buf);
	reset_tokenizer(&tokenizer);
}
