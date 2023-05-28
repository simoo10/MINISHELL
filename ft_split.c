/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:10:01 by rbouissa          #+#    #+#             */
/*   Updated: 2023/05/28 12:50:26 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_norm9	*init_norm9(void)
{
	t_norm9	*norm;

	norm = malloc(sizeof(t_norm9));
	norm->i = 0;
	norm->z = 0;
	return (norm);
}

int	count_tab(char *s, char c)
{
	int	i;
	int	cmpt;

	cmpt = 0;
	i = 0;
	if (!s || !c)
		return (-1);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			cmpt++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (cmpt);
}

char	**ft_split(char *s, char c)
{
	char	**split;
	t_norm9	*no;

	no = init_norm9();
	split = NULL;
	split = split11(s, c, split);
	if (!split)
		return (0);
	if (s == NULL)
	{
		split[0] = 0;
		split[no->z] = NULL;
	}
	else
		split = split_last(split, no, s, c);
	free(no);
	return (split);
}
