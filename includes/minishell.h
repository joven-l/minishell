/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:36:00 by joloo             #+#    #+#             */
/*   Updated: 2025/08/01 16:36:19 by joloo            ###   ########.fr       */
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
	ECHO,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	UNQUOTED,
	SINGLE_QUOTED,
	DOUBLE_QUOTED,
	REDIR_IN,
	REDIR_OUT,
	HERE_DOC,
	APPEND,
	PIPE,
	VAR,
	COMMAND,
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
	char	**token_lookup;
}			t_data;

// free_exit.c
void	free_exit(t_data *data, int exit_code);

// init.c
void	init(t_data *data, char **envp);

// read_input.c
void	read_input(t_data *data);

// signals.c
void	handler_inter(int sig);
void	handler(int sig);

// start.c
void	start(t_data *data);

// tokenize.c
void	tokenize(t_data *data);

#endif