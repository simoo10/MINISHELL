/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:54:47 by met-tahe          #+#    #+#             */
/*   Updated: 2023/05/12 17:50:13 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

# define NO_QUOTES 0
# define ISINGLE_QUOTES 1
# define IDOUBLE_QUOTES 2

typedef struct s_mini
{
	int				valid;
	char			*data_var;
	char			*data_val;
	struct s_mini	*next;
}					t_mini;

typedef struct s_list
{
	char			*data;
	int				token;
	struct s_list	*next;
}					t_list;

typedef struct s_norm
{
	char			*cmd;
	char			*hrd;
	char			**herdoc;
	char			**full_cmd;
	int				check;
	char			*spliter;
	int				token;
	int				token2;
}					t_norm;
typedef struct s_cmd
{
	char			**herdoc;
	char			**cmd;
	int				infile;
	int				outfile;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_vars
{
	int				**fd;
	int				pip_count;
	int				i;
	char			**paths;
	int				check;
	int				stat1;
	int				n;
}					t_vars;

typedef struct s_echo
{
	int				n;
	size_t			i;
	int				j;
	int				nb_arg;
}					t_echo;

typedef struct s_global
{
	t_list			*m_cmd;
	t_mini			*m_env;
	int				status;
	int				hrdsize;
	int				**hrd;
	int				hrd_id;
	int				count_cmd;
	pid_t			*id;
}					t_global;

typedef struct s_main
{
	char			*str;
	char			*str_2;
	int				i;
	int				k;
	struct termios	term;
	struct termios	term2;
}					t_main;
typedef struct s_nor_sp
{
	int				i;
	int				e;
	char			*node;
	char			*st;
	int				j;
	int				k;
	int				check;
	int				token;
	int				quotes;
	int				check_q;
}					t_nor_sp;
typedef struct s_norm2
{
	char			*new_str;
	char			*var;
	char			*valeur;
	char			*dollar;
	int				quotes;
	int				i;
	int				k;
	int				j;
	int				e;
	int				h;

}					t_norm2;
typedef struct s_norm8
{
	int				i;
	int				j;
	int				t;
}					t_norm8;
typedef struct s_norm9
{
	int				i;
	int				z;
}					t_norm9;

t_global			*g_global;

/*-----------------------------------MY PART--------------------------------*/
t_cmd				*ft_last_new(void *tmp);
void				ft_pwd(void);
int					ft_strchr(char *s, int c);
t_list				*ft_last(void *tmp);
int					ft_strncmp(char *s1, char *s2, int len);
void				ft_env(t_mini *lst);
t_list				*sort_list(t_list *lst, int (*cmp)(char *, char *));
void				freestack(t_list **stack);
void				cd_error(char *path);
void				add_back_lst(t_mini **lst, t_mini *new);
t_mini				*ft_add_new(char *var, char *value, int valid);
t_mini				*last_lst(t_mini *a);
t_mini				*env_iniit(char **env);
char				*ft_substr(char *s, int start, int len);
char				**var_split(char *s, char c);
void				ft_putstr_fd(char *s, int fd);
void				ft_export(char *var);
int					ft_atoi(char *str);
int					s_digit(char *s);
void				ft_free(char **str);
int					check_error(char *s);
void				exec_cmd(t_mini *mini, t_cmd *cmd, char **env);
void				echo(char **cmd);
void				ft_unset(char *var, t_mini **tmp);
void				ft_cd(char *path, t_mini *lst);
char				*heredoc(char **herdoc);
char				*get_path(void);
void				execute(char **cmd, char **paths, char **env);
void				close_pipes(int pip_count, int **fd);
void				close_pipes2(int pip_count, int **fd, char **herdoc);
void				fct_error(char *str);
void				shell_error(char *str);
void				ft_exit(char **str);
void				parent_closing(int i, int pip_count, int **fd,
						char **herdoc);
void				ctrlc_handler(int sig);
void				ctrld_handler(int sig);
void				sig_sil(int sig);
void				rl_replace_line(const char *text, int clear_undo);
void				multiple_cmd(t_cmd **cmd, t_vars *vars, char **env, int *n);
int					ft_tolower(int c);
void				struct_free(t_vars *vars);
void				global_free(void);
void				check_parent(t_vars **vars);
void				heredoc_child(int *stat1, t_cmd *tmp1, char *line, int *j);
void				read_heredoc(t_cmd *cmd, int *stat1);
void				mini_builtins1(char **cmd, t_mini *mini);
int					builts_without_pipe(t_cmd *cmd, t_mini *mini);
int					execute_builts(t_mini *mini, char **cmd);
int					hrdpipe_num(t_cmd *tmp);
void				pipe_herdoc(t_cmd *cmd);
void				mini_execution(char **cmd, char **env);
void				child_execution(t_cmd *cmd, char **paths, char **env,
						int *n);
void				sort_in_pipe(int pip_count, int **fd, int i);
void				parent_waiting_uniq(int **fd, int *i, t_cmd *cmd);
void				parent_waiting(t_cmd **cmd, int i, int **fd, int *n);
char				**cmd_paths(t_mini *mini);
void				one_cmd(t_cmd *cmd, t_vars *vars, char **env, int *n);
int					count_pipes(t_cmd *cmd);
void				pipes_creation(int pip_count, int **fd);
int					**allocate_fd(int **fd, int pip_count, t_cmd *cmd);
void				initiate_vars_structe(t_vars **vars, t_mini *mini,
						t_cmd *cmd);
void				cd_with_symbol(char *path, t_mini *tmp);
int					print_export_err(char *var);
char				*oldpwd_change(char *path, t_mini *tmp);
int					is_allpha(char s);
int					is_digit(char s);
int					is_valid(char *s);
void				export_null(char *var);
void				check_sl_zero(t_cmd *cmd);
void				init_my_global(void);
t_main				*init_main_struct(void);
t_main				*main_take(t_main *m);
/*---------------------------------REDA PART--------------------*/
char				**ft_split(char *s, char c);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strjoin(char *left_str, char *buff);
t_list				*split_fuul_cmd(char **s);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strdup(char *src);
char				**split_command(char *str);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstnew(char *content, int t);
void				ft_write(char *s);
int					check_string(char *str);
size_t				ft_strlen(char *s);
t_list				*ft_split_them(char *str);
t_cmd				*ft_lstnew_new(char **content, int t, int k, char **her);
void				ft_lstadd_back_new(t_cmd **lst, t_cmd *new);
t_cmd				*split_to_commands(t_list *comm);
int					ther_are_pipe(char *str);
char				*handle_quotes(char *str, t_mini *env);
int					find_spliter(char s, char *sp);
char				*ft_itoa(int n);
int					check_eroor(char *str);
char				*remove_quotes(t_list *node);
int					size_of_quotes(char *c);
char				*string_no_quotes(char *str);
char				*new_expand(char *str, t_mini *env);
int					find_spliter1(char s, char *sp);
int					is_digit1(char s);
int					is_allpha1(char s);
char				*finnd_valeur(t_mini *env, char *str);
int					ft_check_cote(char *str, int i);
void				ft_free_cmd2(t_cmd *list);
void				ft_free_cmd(t_list *list);
void				send_cmd(t_list **cmd, t_cmd **commands, char *str_2);
int					check_in_main(char *str_2);
int					norm_err3(char *str, int *i);
int					space_checking(char *s);
void				freestack_last(t_list **stack);
int					file_numb(t_list *command);
int					her_pip(t_list *cmd);
int					file_numb2(t_list *command);
t_norm				*init_norm(void);
void				one_cmd_splited(t_norm **norm, t_list **command,
						t_list **comm);
t_cmd				*one_cmd_checking(t_norm **norm, t_cmd *list);
t_cmd				*no_herdoc_check(t_norm **norm, t_cmd *list);
t_cmd				*herd_pi(t_norm **norm, t_cmd *list);
t_cmd				*no_herd_pi(t_norm **norm, t_cmd *list);
t_cmd				*her11(t_norm **norm, t_cmd *list);
t_cmd				*her12(t_norm **norm, t_cmd *list);
void				join_hrd(t_norm **norm, t_list **command);
void				join_cmd(t_norm **norm, t_list **command);
int					in_out_red(t_norm **norm, t_list **comm, t_list **command);
t_cmd				*split_one_cmd(t_list **command, t_norm **norm,
						t_list **comm, t_cmd *list);
void				redifine_norm(t_norm **norm);
t_cmd				*pipe_red(t_norm **norm, t_list **command, t_list **comm,
						t_cmd *list);
void				join_hrd_last(t_norm **norm, t_list **command);
int					find_spliter(char s, char *sp);
int					my_token(char *s);
t_nor_sp			*norm_sp(void);
int					count_nosplit(t_nor_sp **norm, char *str);
char				*fill_quotes(t_nor_sp **norm, char *str);
char				*fill_node(t_nor_sp **norm, char *str);
int					count_spl(t_nor_sp **norm, char *str);
char				*fill_sp(t_nor_sp **norm, char *str);
void				fill_struct(t_nor_sp **norm, t_list **s, char *str);
void				fill_struct2(t_nor_sp **norm, t_list **s, char *str);
int					is_allpha1(char s);
int					is_digit1(char s);
int					find_spliter1(char s, char *sp);
char				*finnd_valeur(t_mini *env, char *str);
t_norm2				*norm_sp1(void);
void				for_dollar(t_norm2 **norm, char *str);
void				alloc_built(t_norm2 **norm, char *str);
void				alloc_simple(t_norm2 **norm, char *str);
char				*join_character(t_norm2 **norm, char *str, t_mini **env,
						char *new_str);
char				*lite_expand(t_norm2 **norm, char *str, t_mini **env,
						char *new_str);
void				join_cmd_last(t_norm **norm, t_list **command);
void				error_msg(char *s);
void				size_of_double(char *c, int *i, int *j);
void				size_of_single(char *c, int *i, int *j);
void				full_str_single_quotes(char *str, char *string, int *i,
						int *j);
void				full_str_double_quotes(char *str, char *string, int *i,
						int *j);
char				**split_last(char **split, t_norm9 *no, char *s, char c);
t_norm9				*init_norm9(void);
char				**split11(char *s, char c, char **split);
int					count_tab(char *s, char c);
int					alot_of_spliter(char *s);
int					size_list(t_list *a);
void				ft_lstadd_front(t_list *lst, t_list *new);
t_list				*ft_lstnew_cmd(char **content, int t);
void				fct_return(void);
int					norm_err1(char *str, int i);
#endif
