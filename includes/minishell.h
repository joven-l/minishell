/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:36:00 by joloo             #+#    #+#             */
/*   Updated: 2025/07/27 20:19:16 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "../libft/includes/libft.h"

typedef	enum e_type
{
	
}	t_type;

typedef struct s_cmd
{
	char			*path;
	char			**args;
	char			**envp;
	int				infile;
	int				outfile;
	int				stdout;
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
	t_cmd	*cmd;
	t_token	*token;
}	t_data;

// free_exit.c
void	free_exit(t_data *data, int exit_code);

// init.c
void	init(t_data *data, char **envp);

// start.c
void	start(t_data *data)

#endif