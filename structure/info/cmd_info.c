/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:51:01 by mypark            #+#    #+#             */
/*   Updated: 2022/04/12 03:40:07 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"
#include "libft.h"
#include "strict.h"
#include <stdlib.h>
#include "constant.h"

t_cmd_info	*new_cmd_info(char *cmd, char **args, char ***envp)
{
	t_cmd_info	*info;

	info = strict_malloc(sizeof(t_cmd_info), 1);
	info->cmd = cmd;
	info->args = args;
	info->envp = envp;
	return (info);
}

void	free_cmd_info(t_cmd_info *info)
{
	if (info == FT_NULL)
		return ;
	free(info->cmd);
	ft_splitfree(info->args);
	free(info);
}
