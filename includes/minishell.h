/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:36:00 by joloo             #+#    #+#             */
/*   Updated: 2025/08/26 12:59:47 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct sigaction	t_sig;

// here_doc/append is <</>>
// var is $
typedef enum e_type
{
	HERE_DOC,
	APPEND,
	REDIR_IN,
	REDIR_OUT,
	PIPE,
	VAR,
	SINGLE_QUOTED,
	DOUBLE_QUOTED,
	UNQUOTED,
	SPACES,
}	t_type;

typedef struct s_cmd
{
	char			*path;
	char			**args;
	char			**envp;
	int				infile;
	int				outfile;
	int				stdout;
	int				append;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_token
{
	char			*content;
	t_type			type;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

typedef struct s_data
{
	char	**envp;
	pid_t	*pid;
	int		**pipes;
	char	*input;
	t_sig	sig;
	t_sig	sig_inter;
	t_cmd	*cmd;
	t_token	*token;
	t_token	*token_last;
	char	**token_lookup;
}			t_data;

// envp.c
void	builtin_export(t_data *data);

// free.c
void	free_exit(t_data *data, int exit_code);
void	free_prompt(t_data *data);

// init.c
void	init(t_data *data, char **envp);
void	init_lookup(t_data *data);

// read_input.c
void	read_input(t_data *data);

// signals.c
void	handler_inter(int sig);
void	handler(int sig);

// start.c
void	start(t_data *data);

// token_handle.c
int		handle_operator(t_data *data, int *i, int type);
int		handle_squote(t_data *data, int *i);
int		handle_dquote(t_data *data, int *i);
int		handle_unquoted(t_data *data, int *i, int *j);

// tokenize.c
int		tokenize(t_data *data);
int	 detect_operator(t_data *data, int *i, int *j);
void	add_node(t_data *data, int start, int len, int type);

#endif