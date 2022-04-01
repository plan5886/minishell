/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:23:58 by mypark            #+#    #+#             */
/*   Updated: 2022/04/01 22:37:18 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_UTILS_H
# define PARSER_UTILS_H
# include "parse_tree.h"

int					parse_redir(t_parsetree_node *pt_node);
int					parse_bool(t_parsetree_node *pt_node);
int					parse_pipe(t_parsetree_node *pt_node);
int					is_edge_parentheses(t_parsetree_node *pt_node);
void				remove_edge_parentheses(t_parsetree_node *pt_node);
t_tokens_node		*pass_parentheses_forward(t_tokens_node *curr);
t_tokens_node		*pass_parentheses_backward(t_tokens_node *curr);

#endif
