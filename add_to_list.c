/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:00:37 by met-tahe          #+#    #+#             */
/*   Updated: 2023/05/28 13:00:38 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	norm_err2(char *str, int i)
{
	i++;
	while (str[i] && (str[i] == '\t' || str[i] == ' '))
		i++;
	return (i);
}

int	check_all_return_lite(char *str, int *i)
{
	if (str[(*i) + 1] == ' ' || str[(*i) + 1] == '\t' || str[(*i) + 1] == '|')
	{
		(*i) = norm_err2(str, (*i));
		if (!str[(*i)] || str[(*i)] == '|')
			return (fct_return(), 0);
	}
	else if (!str[(*i) + 1])
		return (fct_return(), 0);
	return (1);
}

int	check_all_return(char *str, int *i)
{
	if ((str[0] == ' ' || str[0] == '\t'))
	{
		(*i) = norm_err1(str, (*i));
		if ((str[*i] == '|' || str[(*i)] == '>' || str[(*i)] == '<'))
			return (fct_return(), 0);
		else if (str[(*i)])
			(*i)++;
	}
	else if (str[0] == '|')
		return (fct_return(), 0);
	else if (str[(*i)] == '|' && (!str[(*i) + 1] || (str[(*i) + 1] == '\t'
				|| str[(*i) + 1] == ' ' || str[(*i) + 1] == '|')))
	{
		if (!check_all_return_lite(str, i))
			return (0);
	}
	else if ((str[(*i)] == '>' || str[(*i)] == '<') && !str[(*i) + 1])
		return (fct_return(), 0);
	else
		(*i)++;
	return (1);
}

int	check_eroor(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!check_all_return(str, &i))
			return (0);
	}
	return (1);
}
