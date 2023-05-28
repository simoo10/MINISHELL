CFLAGS	= -Wall -Wextra -Werror 
LIBC	= ar -rc
RM		= rm -f
NAME	= minishell
SRC		= main.c \
			ft_split.c \
			main_utils.c \
			main_utils2.c \
			ft_split1.c \
			libft_helpers.c \
			libft_helpers2.c \
			libft_helpers3.c \
			libft_helpers4.c \
			builtins/ft_cd.c \
			builtins/ft_echo.c \
			builtins/ft_env.c \
			builtins/ft_pwd.c \
			builtins/ft_unset.c \
			list_utils.c \
			list_utils2.c \
			list_utils3.c \
			builtins/ft_export.c \
			builtins/ft_export_print.c \
			builtins/ft_error.c \
			builtins/ft_exit.c \
			execution/pipes.c \
			execution/heredoc.c \
			add_to_list.c \
			add_to_list2.c \
			test_split.c \
			creat_list_command.c \
			execution/signals.c \
			execution/free_fct.c \
			execution/builtins_execution.c \
			execution/chilld_exec.c \
			execution/parent_exec.c \
			execution/exec_cmd.c \
			freed.c \
			quotes.c\
			quotes2.c\
			new_env.c\
			creat_list_command1.c\
			creat_list_command2.c\
			creat_commad_list3.c\
			creat_command_list4.c\
			test_split1.c\
			test_split2.c\
			new_env1.c\
			new_env2.c\

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS)  $(OBJ) -o $(NAME)  -lreadline -L /Users/met-tahe/goinfre/homebrew/opt/readline/lib -I /Users/met-tahe/goinfre/homebrew/opt/readline/include 

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME) 

re:	fclean all

b: all clean
