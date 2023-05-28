/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:36:00 by met-tahe          #+#    #+#             */
/*   Updated: 2023/05/28 12:36:04 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_in_main(char *str_2)
{
	if (str_2 != NULL && check_eroor(str_2) && alot_of_spliter(str_2))
		return (1);
	else
		return (0);
}

void	send_cmd(t_list **cmd, t_cmd **commands, char *str_2)
{
	*cmd = ft_split_them(str_2);
	*commands = split_to_commands(*cmd);
	check_sl_zero(*commands);
}

void	check_sl_zero(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		i;

	tmp = cmd;
	i = -1;
	while (tmp)
	{
		i = -1;
		while (tmp->cmd[++i])
		{
			if (ft_strcmp(tmp->cmd[i], "\"\"") == 0)
			{
				free(tmp->cmd[i]);
				tmp->cmd[i] = ft_strdup("\0");
			}
		}
		tmp = tmp->next;
	}
}

int	alot_of_spliter(char *s)
{
	int	i;

	i = 0;
	while (find_spliter(s[i], "|<> \t"))
		i++;
	if (s[i] && !find_spliter(s[i], "|<> \t"))
		return (1);
	else
		return (0);
}
