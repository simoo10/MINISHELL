/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:53:20 by met-tahe          #+#    #+#             */
/*   Updated: 2023/03/08 11:53:21 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	s_digit(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if ((s[i] >= 48 && s[i] <= 57))
			i++;
		else
			return (0);
	}
	return (1);
}

void	exit_fct_error(char *s)
{
	printf("exit\nminishell: exit: %s: numeric argument required\n", s);
	exit(g_global->status = 255);
}

int	ft_atoi(char *str)
{
	size_t	i;
	size_t	n;
	size_t	r;

	r = 0;
	i = 0;
	n = 0;
	if (str[i] == '\0')
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			n = 1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i++] - '0';
		if (r > __LONG_MAX__ + (n == 1))
			exit_fct_error(str);
	}
	if (n)
		r = r * (-1);
	return (r);
}

void	ft_exit(char **status)
{
	if (status[1] == NULL)
		(printf("exit\n"), exit(g_global->status = 0));
	else if (s_digit(status[1]) == 0)
	{
		printf("exit\nbash: exit: %s: numeric argument required\n", status[1]);
		exit(g_global->status = 255);
	}
	else if (status[2])
	{
		printf("exit\nminishell: exit: too many arguments\n");
		g_global->status = 1;
		return ;
	}
	else
	{
		g_global->status = ft_atoi(status[1]);
		if (g_global->status < 0 || g_global->status > 255)
			g_global->status = g_global->status % 256;
		(printf("exit\n"), exit(g_global->status));
	}
}
