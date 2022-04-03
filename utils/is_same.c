/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_same.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:09:58 by mypark            #+#    #+#             */
/*   Updated: 2022/03/31 18:10:10 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_same(char *s1, char *s2)
{
	if (ft_strncmp(s1, s2, -1) == 0)
		return (1);
	return (0);
}