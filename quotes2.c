/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:13:24 by met-tahe          #+#    #+#             */
/*   Updated: 2023/05/28 13:13:26 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	size_of_double(char *c, int *i, int *j)
{
	(*i)++;
	while (c[*i] && c[*i] != '\"')
	{
		(*i)++;
		(*j)++;
	}
}

void	size_of_single(char *c, int *i, int *j)
{
	(*i)++;
	while (c[*i] && c[*i] != '\'')
	{
		(*i)++;
		(*j)++;
	}
}

int	size_of_quotes(char *c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (c[i] != '\0')
	{
		if (c[i] == '\"')
		{
			size_of_double(c, &i, &j);
			if (c[i])
				i++;
			continue ;
		}
		if (c[i] == '\'')
		{
			size_of_single(c, &i, &j);
			if (c[i])
				i++;
			continue ;
		}
		i++;
		j++;
	}
	return (j);
}

void	full_str_single_quotes(char *str, char *string, int *i, int *j)
{
	(*i)++;
	while (str[*i] && str[*i] != 39)
	{
		string[*j] = str[*i];
		(*i)++;
		(*j)++;
	}
}

void	full_str_double_quotes(char *str, char *string, int *i, int *j)
{
	(*i)++;
	while (str[*i] && str[*i] != 34)
	{
		string[*j] = str[*i];
		(*i)++;
		(*j)++;
	}
}
