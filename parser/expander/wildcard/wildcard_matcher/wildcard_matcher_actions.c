/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_matcher_actions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 00:18:12 by mypark            #+#    #+#             */
/*   Updated: 2022/04/05 12:42:04 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard_matcher.h"
#include "utils.h"
#include "test.h"

void	wildcard_matcher_compare(\
	t_wildcard_matcher *matcher, \
	char *word, \
	int *wi
)
{
	int		len;
	char	*curr_pattern;

	curr_pattern = matcher->get_curr_pattern(matcher);
	len = ft_strlen(curr_pattern);
	if (ft_strncmp(word + (*wi), curr_pattern, len) == 0)
	{
		(*wi) += len;
		matcher->pattern_index++;
		matcher->state = WM_WILDCARD;
	}
	else
		matcher->state = WM_REJECT;
}


void	wildcard_matcher_wildcard(\
	t_wildcard_matcher *matcher, \
	char *word, \
	int *wi
)
{
	char	escape_char;
	char	*curr_pattern;

	curr_pattern = matcher->get_curr_pattern(matcher);
	escape_char = curr_pattern[0];
	if (word[*wi] == escape_char)
		matcher->state = WM_COMPARE;
	else
	{
		(*wi)++;
		matcher->state = WM_WILDCARD;
	}
}