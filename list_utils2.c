/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:39:41 by met-tahe          #+#    #+#             */
/*   Updated: 2023/05/28 12:39:43 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*ft_last_new(void *tmp)
{
	t_cmd	*a;

	a = (t_cmd *)tmp;
	while (a->next)
		a = a->next;
	return (a);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (lst)
	{
		if (*lst)
		{
			ptr = ft_last(*lst);
			ptr->next = new;
		}
		else
			*lst = new;
	}
}

void	ft_lstadd_back_new(t_cmd **lst, t_cmd *new)
{
	t_cmd	*ptr;

	if (lst)
	{
		if (*lst)
		{
			ptr = ft_last_new(*lst);
			ptr->next = new;
		}
		else
			*lst = new;
	}
}

t_cmd	*ft_lstnew_new(char **content, int t, int k, char **her)
{
	t_cmd	*node;

	node = malloc(sizeof(t_cmd));
	if (!node)
		return (NULL);
	node->cmd = content;
	node->infile = t;
	node->outfile = k;
	node->herdoc = her;
	node->next = NULL;
	return (node);
}

int	size_list(t_list *a)
{
	if (a)
		return (1 + size_list(a->next));
	else
		return (0);
}
