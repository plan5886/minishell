/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:36:47 by mypark            #+#    #+#             */
/*   Updated: 2022/04/02 01:32:43 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include "error.h"
#include "expansion_record.h"

void	init_buffer(t_buffer *buf)
{
	buf->start = 0;
	buf->space = 0;
	buf->len = 0;
	buf->cnt = 0;
	buf->quoted = 0;
	buf->expansion_record = NULL;
}

void	reset_buffer(t_buffer *buf)
{
	free(buf->space);
	free_expansion_record(buf->expansion_record);
	init_buffer(buf);
}

void	clear_buffer(t_buffer *buf)
{
	buf->len = 0;
	buf->space[0] = '\0';
	buf->start = 0;
	buf->quoted = 0;
	free_expansion_record(buf->expansion_record);
	buf->expansion_record = NULL;
}

void	expand_buffer(t_buffer *buf)
{
	if (buf->space == 0)
	{
		buf->space = ft_calloc(1, BUFFER_SIZE);
		buf->cnt = 1;
		if (buf->space == 0)
			print_malloc_error();
	}
	else if (buf->len == buf->cnt * BUFFER_SIZE - 1)
	{
		buf->cnt++;
		buf->space = ft_realloc(buf->space, buf->cnt * BUFFER_SIZE);
		if (buf->space == 0)
			print_malloc_error();
	}
}

void	push_buffer(t_buffer *buf, char input)
{
	if (input == '\0')
		return ;
	expand_buffer(buf);
	buf->space[buf->len++] = input;
	buf->space[buf->len] = '\0';
}

void	push_buffer_str(t_buffer *buf, char *str)
{
	while (*str)
	{
		push_buffer(buf, *str);
		str++;
	}
}
