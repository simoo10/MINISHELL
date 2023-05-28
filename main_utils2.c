/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:36:08 by met-tahe          #+#    #+#             */
/*   Updated: 2023/05/28 12:36:10 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ther_are_pipe(char *str)
{
	int	i;
	int	quotes;

	i = 0;
	quotes = 0;
	while (str[i])
	{
		if (str[i] == '|')
			return (1);
		i++;
	}
	return (0);
}

void	print_cmd(t_cmd *cmd)
{
	int		i;
	t_cmd	*tmp;

	i = 0;
	tmp = cmd;
	while (tmp)
	{
		i = 0;
		if (tmp->cmd == NULL)
			printf("cmd = NULL\n");
		while (tmp->cmd && tmp->cmd[i])
		{
			printf("%s\n", tmp->cmd[i]);
			i++;
		}
		printf("infile = %d\n", tmp->infile);
		printf("outfile = %d\n", tmp->outfile);
		i = 0;
		while (tmp->herdoc && tmp->herdoc[i])
		{
			printf("herdoc = %s\n", tmp->herdoc[i]);
			i++;
		}
		tmp = tmp->next;
	}
}

void	init_my_global(void)
{
	g_global->m_cmd = NULL;
	g_global->hrdsize = 0;
	g_global->status = 0;
	g_global->hrd = NULL;
	g_global->hrd_id = 0;
	g_global->count_cmd = 0;
	g_global->id = NULL;
	g_global->status = 0;
}

t_main	*init_main_struct(void)
{
	t_main	*main;

	main = malloc(sizeof(t_main));
	main->str = NULL;
	main->str_2 = NULL;
	main->i = 0;
	main->k = 0;
	return (main);
}

t_main	*main_take(t_main *m)
{
	tcgetattr(0, &(m->term));
	m->term2 = m->term;
	m->term.c_lflag &= ~ISIG;
	m->term.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &(m->term));
	m->str = readline("minishell>");
	tcsetattr(0, TCSANOW, &(m->term2));
	if (!m->str)
		(write(1, "exit\n", 5), free(m->str), exit(g_global->status));
	add_history(m->str);
	return (m);
}
