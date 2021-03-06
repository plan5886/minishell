/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expander.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 01:46:22 by mypark            #+#    #+#             */
/*   Updated: 2022/04/22 08:17:26 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_EXPANDER_H
# define ENV_EXPANDER_H
# include "buffer.h"
# include "token.h"
# include "expansion_record.h"

typedef enum e_env_expander_state
{
	E_CHARS,
	E_SINGLE_QUOTE,
	E_DOUBLE_QUOTE,
	E_EXPAND,
	E_DQ_EXPAND
}			t_env_expander_state;

typedef struct s_env_expander
{
	t_env_expander_state	state;
	t_buffer				*buf;
	int						(*actions[5])(struct s_env_expander *, char);
	char					***envp;
	t_tokens				*tokens;
}				t_env_expander;

#endif
