/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:53:27 by met-tahe          #+#    #+#             */
/*   Updated: 2023/03/08 11:53:29 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	search_exp(char *s)
{
	t_mini	*tmp;

	tmp = g_global->m_env;
	while (tmp)
	{
		if (ft_strcmp(tmp->data_var, s) == 0)
			return (1);
		else
			tmp = tmp->next;
	}
	return (0);
}

void	export_ecrase(t_mini **tmp1, char **v)
{
	while (*tmp1)
	{
		if (ft_strcmp((*tmp1)->data_var, v[0]) == 0)
		{
			(*tmp1)->valid = 0;
			free((*tmp1)->data_val);
			(*tmp1)->data_val = ft_strdup(v[1]);
			free(v[1]);
			free(v[0]);
			break ;
		}
		else
			*tmp1 = (*tmp1)->next;
	}
}

void	export_join(t_mini **tmp1, char **v)
{
	while (*tmp1)
	{
		if (ft_strcmp((*tmp1)->data_var, v[0]) == 0)
		{
			(*tmp1)->valid = 0;
			(*tmp1)->data_val = ft_strjoin((*tmp1)->data_val, v[1]);
			free(v[1]);
			free(v[0]);
			break ;
		}
		else
			*tmp1 = (*tmp1)->next;
	}
}

void	export_with_egal(char *var, char **v, int q)
{
	t_mini	*tmp1;

	tmp1 = g_global->m_env;
	if (ft_strchr(var, '='))
	{
		if (search_exp(v[0]) == 0)
			add_back_lst(&g_global->m_env, ft_add_new(v[0], v[1], 0));
		else if (search_exp(v[0]) == 1 && q == 0)
			export_ecrase(&tmp1, v);
		else if (search_exp(v[0]) == 1 && q == 10)
			export_join(&tmp1, v);
	}
	else
	{
		if (search_exp(v[0]) == 0)
			add_back_lst(&g_global->m_env, ft_add_new(v[0], v[1], 1));
		else
			free(v[0]);
	}
}

void	ft_export(char *var)
{
	char	**v;
	int		i;
	char	*s;
	int		q;

	q = 0;
	i = 0;
	s = NULL;
	v = NULL;
	export_null(var);
	if (var != NULL)
	{
		if (print_export_err(var) == 1)
			return ;
		v = var_split(var, '=');
		if (v[0][ft_strlen(v[0]) - 1] == '+')
		{
			q = 10;
			s = ft_strdup(v[0]);
			free(v[0]);
			v[0] = ft_substr(v[0], 0, ft_strlen(v[0]) - 1);
		}
		export_with_egal(var, v, q);
		(free(s), free(v));
	}
}
