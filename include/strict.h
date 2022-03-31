/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strict.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 01:45:04 by mypark            #+#    #+#             */
/*   Updated: 2022/04/01 02:34:34 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRICT_H
# define STRICT_H
# include <sys/types.h>

void	*strict_malloc(int size, int count);
pid_t	strict_fork(int size, int count);
void	strict_dup2(int srcfd, int dstfd);
void	strict_close(int fd);

#endif
