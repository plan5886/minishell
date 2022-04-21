/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_splited.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:35:06 by mypark            #+#    #+#             */
/*   Updated: 2022/04/04 16:43:31 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	print_splited(char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
	{
		printf("\t %02d : %s\n", i, splited[i]);
		i++;
	}
}