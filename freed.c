/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:52:11 by met-tahe          #+#    #+#             */
/*   Updated: 2023/05/28 12:52:12 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_cmd(t_list *list)
{
	t_list	*node;

	node = NULL;
	if (!list)
		return ;
	while (list)
	{
		node = list;
		list = list->next;
		free(node->data);
		free(node);
	}
	free(list);
}

void	ft_free_cmd2(t_cmd *list)
{
	t_cmd	*node;
	int		i;

	i = 0;
	node = NULL;
	if (!list)
		return ;
	while (list)
	{
		i = -1;
		node = list;
		list = list->next;
		while (node->cmd[++i])
			free(node->cmd[i]);
		(free(node->cmd[i]), free(node->cmd));
		i = -1;
		while (node->herdoc[++i])
			free(node->herdoc[i]);
		(free(node->herdoc[i]), free(node->herdoc), free(node));
	}
	free(list);
}
