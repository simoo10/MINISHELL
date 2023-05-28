/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:11:43 by met-tahe          #+#    #+#             */
/*   Updated: 2023/05/28 13:11:46 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	export_null(char *var)
{
	t_mini	*tmp;

	tmp = g_global->m_env;
	if (var == NULL)
	{
		while (tmp)
		{
			if ((tmp)->data_val)
				printf("declare -x %s=\"%s\"\n", (tmp)->data_var,
					(tmp)->data_val);
			else
				printf("declare -x %s\n", (tmp)->data_var);
			tmp = (tmp)->next;
		}
	}
}
