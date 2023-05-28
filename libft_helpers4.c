/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_helpers4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:48:41 by met-tahe          #+#    #+#             */
/*   Updated: 2023/05/28 12:48:44 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		i++;
	}
	write(fd, s, i);
}

int	is_allpha(char s)
{
	if ((s >= 65 && s <= 90) || (s >= 97 && s <= 122) || s == '_')
		return (1);
	return (0);
}

int	is_digit(char s)
{
	if ((s >= 48 && s <= 57))
		return (1);
	return (0);
}

int	is_valid(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (is_allpha(s[i]) == 0 && is_digit(s[i]) == 0 && s[i] != '=')
			return (0);
		i++;
	}
	return (1);
}
