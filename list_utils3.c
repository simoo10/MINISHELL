/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:42:44 by met-tahe          #+#    #+#             */
/*   Updated: 2023/05/28 12:42:45 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

struct s_list	*ft_lstnew(char *content, int t)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = content;
	node->token = t;
	node->next = NULL;
	return (node);
}

t_list	*ft_lstnew_cmd(char **content, int t)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = *content;
	node->token = t;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_front(t_list *lst, t_list *new)
{
	new->next = lst;
	lst = new;
}

t_list	*ft_last(void *tmp)
{
	t_list	*a;

	a = (t_list *)tmp;
	while (a->next)
		a = a->next;
	return (a);
}
