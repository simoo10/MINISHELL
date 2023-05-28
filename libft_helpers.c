/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:49:07 by met-tahe          #+#    #+#             */
/*   Updated: 2023/05/28 12:49:09 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_intlen(int numb)
{
	int	cmpt;

	cmpt = 0;
	if (numb == 0)
	{
		cmpt++;
	}
	if (numb < 0)
	{
		numb = numb * (-1);
		cmpt++;
	}
	while (numb != 0)
	{
		numb = numb / 10;
		cmpt++;
	}
	return (cmpt);
}

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}

char	*ft_itoa(int n)
{
	int		i;
	long	j;
	char	*numb;

	j = n;
	numb = (char *)(malloc(sizeof(char) * ft_intlen(n) + 1));
	i = ft_intlen(n) - 1;
	if (!numb)
		return (0);
	if (j < 0)
	{
		j = j * (-1);
		numb[0] = '-';
	}
	while (j != 0)
	{
		numb[i] = j % 10 + 48;
		j = j / 10;
		i--;
	}
	if (n == 0)
		numb[0] = '0';
	numb[ft_intlen(n)] = '\0';
	return (numb);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1 == NULL)
	{
		return (2);
	}
	if (s2 == NULL)
	{
		return (2);
	}
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if ((unsigned char)s1[i] < (unsigned char)s2[i])
		{
			return (-1);
		}
		else if ((unsigned char)s1[i] > (unsigned char)s2[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}
