/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:52:13 by met-tahe          #+#    #+#             */
/*   Updated: 2023/05/27 18:52:18 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
//cat Makefile >1| <<k <<l<<l cat>>1|ls|wc|cat >>1
//<Makefile cat <main.c | wc -l;

// t_global			*my_global;

t_mini	*main_initialisation(char **env, t_main **m)
{
	t_mini	*mini;

	*m = init_main_struct();
	g_global = malloc(sizeof(t_global));
	mini = env_iniit(env);
	g_global->m_env = mini;
	init_my_global();
	(signal(SIGINT, ctrlc_handler), signal(SIGQUIT, ctrld_handler));
	return (mini);
}

void	check_free(t_main **m, t_cmd **commands)
{
	free((*m)->str);
	(*m)->str = NULL;
	if ((*m)->str_2 != NULL)
		free((*m)->str_2);
	if ((*m)->str_2 != NULL && (*m)->k)
	{
		(*m)->k = 0;
		ft_free_cmd2(*commands);
		*commands = NULL;
		(*m)->str_2 = NULL;
	}
}

void	expand_and_take(t_mini **mini, t_main **m)
{
	*m = main_take(*m);
	(*m)->str_2 = new_expand((*m)->str, *mini);
}

int	main(int argc, char **argv, char **env)
{
	t_list	*cmd;
	t_cmd	*commands;
	t_mini	*mini;
	t_main	*m;

	(void)argc;
	(void)argv;
	mini = main_initialisation(env, &m);
	while (1)
	{
		expand_and_take(&mini, &m);
		if (m->str_2 != NULL && check_in_main(m->str_2))
		{
			m->k = 1;
			if (m->str_2[0])
			{
				send_cmd(&cmd, &commands, m->str_2);
				if (commands == NULL)
					continue ;
				exec_cmd(mini, commands, env);
			}
		}
		check_free(&m, &commands);
	}
}
