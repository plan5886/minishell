/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:15:05 by mypark            #+#    #+#             */
/*   Updated: 2022/04/05 17:34:28 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "info.h"
#include "builtin.h"
#include "test.h"

int	is_builtin(char *cmd)
{
	static char	*builtins[] = { /*"echo", */\
							"cd", \
							"pwd", \
							"export", \
							"unset", \
							"env", \
							"exit",
							0
	};
	int			i;

	i = 0;
	while (builtins[i])
	{
		if(is_same(builtins[i], cmd))
			return (1);
		i++;
	}
	return (0);
}

int	exe_builtin(t_cmd_info *info)
{
	printf("builtin\n");
	if (info == NULL)
		return (0);
	if (is_same(info->cmd, "cd"))
		return (builtin_cd(info->args[1], info->envp));
	if (is_same(info->cmd, "pwd"))
		return (builtin_pwd());
	return (0);
}
