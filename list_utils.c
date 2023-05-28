/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:37:50 by met-tahe          #+#    #+#             */
/*   Updated: 2023/05/28 12:37:52 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mini	*ft_add_new(char *var, char *value, int valid)
{
	t_mini	*node;

	node = malloc(sizeof(t_mini));
	if (!node)
		return (NULL);
	node->data_var = var;
	node->data_val = value;
	node->valid = valid;
	node->next = NULL;
	return (node);
}

void	add_back_lst(t_mini **lst, t_mini *new)
{
	t_mini	*ptr;

	if (lst)
	{
		if (*lst)
		{
			ptr = last_lst(*lst);
			ptr->next = new;
		}
		else
			*lst = new;
	}
}

t_mini	*last_lst(t_mini *a)
{
	while (a->next)
		a = a->next;
	return (a);
}
