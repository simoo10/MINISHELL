/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 21:18:58 by met-tahe          #+#    #+#             */
/*   Updated: 2023/05/19 21:19:03 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_in_out(t_cmd **cmd, int *i)
{
	if ((*cmd)->infile == -1 || (*cmd)->outfile == -1)
	{
		*cmd = (*cmd)->next;
		(*i)++;
		return (1);
	}
	return (0);
}

void	exec_cmd(t_mini *mini, t_cmd *cmd, char **env)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	initiate_vars_structe(&vars, mini, cmd);
	vars->fd = allocate_fd(vars->fd, vars->pip_count, cmd);
	read_heredoc(cmd, &(vars->stat1));
	if (!vars->stat1 && vars->pip_count == 0)
		one_cmd(cmd, vars, env, &(vars->n));
	else
	{
		vars->i = 0;
		while (!vars->stat1 && cmd && vars->i <= vars->pip_count)
		{
			if (check_in_out(&cmd, &(vars->i)) == 1)
				continue ;
			vars->check = 1;
			g_global->id[vars->i] = fork();
			multiple_cmd(&cmd, vars, env, &(vars->n));
			(vars->i)++;
		}
		if (vars->check == 1)
			check_parent(&vars);
	}
	(struct_free(vars), global_free());
}

void	multiple_cmd(t_cmd **cmd, t_vars *vars, char **env, int *n)
{
	if (g_global->id[vars->i] < 0)
		fct_error("fork");
	else if (g_global->id[vars->i] == 0)
	{
		signal(SIGINT, SIG_DFL);
		sort_in_pipe(vars->pip_count, vars->fd, vars->i);
		child_execution(*cmd, vars->paths, env, n);
	}
	else
		parent_waiting(cmd, vars->i, vars->fd, n);
}

void	one_cmd(t_cmd *cmd, t_vars *vars, char **env, int *n)
{
	int	status;

	status = 0;
	if (cmd->infile == -1 || cmd->outfile == -1)
		return (free(g_global->id));
	if (builts_without_pipe(cmd, g_global->m_env) == 1)
		return (free(g_global->id));
	g_global->id[vars->i] = fork();
	if (g_global->id[vars->i] < 0)
		fct_error("fork");
	else if (g_global->id[vars->i] == 0)
		child_execution(cmd, vars->paths, env, n);
	else
		parent_waiting_uniq(vars->fd, &(vars->i), cmd);
}

int	count_pipes(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		pipe_count;

	tmp = NULL;
	tmp = cmd;
	pipe_count = 0;
	while (tmp)
	{
		pipe_count++;
		tmp = tmp->next;
	}
	return (pipe_count - 1);
}
