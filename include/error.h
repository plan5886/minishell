/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:23:58 by mypark            #+#    #+#             */
/*   Updated: 2022/04/04 22:42:59 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include "token.h"

int		syntax_error_check(t_tokens *tks);
void	print_malloc_error(void);
void	print_strerror(char *func, char *msg);
void	print_unexpected_token(char *later);
void	print_incorrect_pairs(char *type);

#endif
