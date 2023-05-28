/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:50:20 by met-tahe          #+#    #+#             */
/*   Updated: 2023/05/28 12:50:22 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_strnlen(char *src, char c)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != c)
	{
		i++;
	}
	return (i);
}

static char	*ft_cp(char *src, char c)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strnlen(src, c) + 1));
	if (!dest)
		return (0);
	while (src[i] && src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

static void	free_split(char **s, int z)
{
	while (z >= 0)
		free(s[z--]);
	free(s);
	return ;
}

char	**split11(char *s, char c, char **split)
{
	if (s != NULL)
		split = (char **)malloc(sizeof(char *) * (count_tab(s, c) + 1));
	else
		split = malloc(sizeof(char *));
	return (split);
}

char	**split_last(char **split, t_norm9 *no, char *s, char c)
{
	while (s[no->i])
	{
		while (s[no->i] && s[no->i] == c)
			(no->i)++;
		if (s[no->i] && s[no->i] != c)
		{
			split[no->z] = ft_cp((char *)s + no->i, c);
			if (!split[no->z])
				free_split(split, no->z);
			(no->z)++;
		}
		while (s[no->i] != c && s[no->i])
			(no->i)++;
	}
	split[no->z] = NULL;
	return (split);
}
