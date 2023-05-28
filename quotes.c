/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:13:18 by met-tahe          #+#    #+#             */
/*   Updated: 2023/05/28 13:13:20 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_norm8	*no_init(char *str)
{
	t_norm8	*no;

	no = malloc(sizeof(t_norm8));
	no->i = 0;
	no->j = 0;
	no->t = size_of_quotes(str);
	return (no);
}

int	check_22(char *str, int *i)
{
	if (str[*i])
	{
		(*i)++;
		return (1);
	}
	return (0);
}

char	*string_no_quotes(char *str)
{
	t_norm8	*no;
	char	*string;

	no = no_init(str);
	string = malloc(no->t + 1);
	while (str[no->i])
	{
		if (str[no->i] == 39)
		{
			full_str_single_quotes(str, string, &(no->i), &(no->j));
			if (check_22(str, &(no->i)))
				continue ;
		}
		if (str[no->i] == 34)
		{
			full_str_double_quotes(str, string, &(no->i), &(no->j));
			if (check_22(str, &(no->i)))
				continue ;
		}
		string[no->j] = str[no->i];
		(no->i)++;
		(no->j)++;
	}
	string[no->j] = '\0';
	return (free(no), string);
}
