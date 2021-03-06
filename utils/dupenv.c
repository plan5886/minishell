/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dupenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:20:09 by mypark            #+#    #+#             */
/*   Updated: 2022/04/12 03:41:26 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "constant.h"

char	*dupenv(char *target, char **envp)
{
	int	ei;
	int	len;

	if (target == FT_NULL || envp == FT_NULL)
		return (ft_strdup(""));
	ei = 0;
	len = ft_strlen(target);
	while (envp[ei])
	{
		if (ft_strncmp(target, envp[ei], len) == 0 && envp[ei][len] == '=')
			return (ft_strdup(envp[ei] + len + 1));
		ei++;
	}
	return (ft_strdup(""));
}
