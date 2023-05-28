/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:54:34 by met-tahe          #+#    #+#             */
/*   Updated: 2023/03/10 17:54:36 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cd_error(char *path)
{
	g_global->status = 1;
	printf("cd: %s: %s\n", path, strerror(errno));
	return ;
}

void	cd_with_symbol(char *path, t_mini *tmp)
{
	path = oldpwd_change(path, tmp);
	if (chdir(path) < 0)
		fct_error("cd");
	else
		printf("%s\n", path);
}

int	check_error(char *s)
{
	size_t	i;
	char	**v;

	v = var_split(s, '=');
	i = 0;
	if (is_allpha(s[i]) == 0)
		return (ft_free(v), 0);
	while (v[0][i])
	{
		if (is_allpha(v[0][i]) || is_digit(v[0][i]) || (v[0][i] == '+'
				&& ft_strchr(s, '=')) || (v[0][i] == '_'))
		{
			if (v[0][i] == '+')
			{
				if (i == ft_strlen(v[0]) - 1)
					i++;
				else
					return (ft_free(v), 0);
			}
			i++;
		}
		else
			return (0);
	}
	return (ft_free(v), 1);
}

int	print_export_err(char *var)
{
	if (check_error(var) == 0)
	{
		ft_putstr_fd("minishell: export:`", 2);
		ft_putstr_fd(var, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		g_global->status = 1;
		return (1);
	}
	else
		return (0);
}
