/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:55:44 by mypark            #+#    #+#             */
/*   Updated: 2022/03/21 14:49:00 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_tree.h"

t_parsetree_node	*new_parsetree_node(t_tokens *tks, t_parsetree_node *parent)
{
	t_parsetree_node	*new;

	new = malloc(sizeof(t_parsetree_node));
	if (new == NULL)
		return (NULL);
	new->left = NULL;
	new->right = NULL;
	new->parent = parent;
	new->tokens = tks;
	new->parsed = 0;
	return (new);
}
