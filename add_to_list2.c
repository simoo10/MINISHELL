/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_list2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:01:39 by met-tahe          #+#    #+#             */
/*   Updated: 2023/05/28 13:01:41 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_string(char *str)
{
	int	i;
	int	k;

	i = 0;
	while (str[i])
	{
		if (str[i] == 39 || str[i] == 34)
		{
			k = str[i];
			i++;
			while (str[i] != k && str[i])
				i++;
			if (str[i] != k)
			{
				ft_write("syntax error exepected quote");
				return (g_global->status = 258, 0);
			}
		}
		i++;
	}
	return (1);
}

void	fct_return(void)
{
	ft_write("syntax error near unexpected token `|'");
	g_global->status = 258;
}

int	norm_err1(char *str, int i)
{
	while ((str[i] == ' ' || str[i] == '\t') && str[i])
		i++;
	return (i);
}
