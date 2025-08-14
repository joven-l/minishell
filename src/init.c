/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:12:42 by joloo             #+#    #+#             */
/*   Updated: 2025/07/27 19:12:42 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init(t_data *data, char **envp)
{
	ft_memset(data, 0, sizeof(data));
	data->envp = ft_strarrdup(envp);
	data->sig.sa_handler = handler;
	data->sig_inter.sa_handler = handler_inter;
	init_lookup(data);
}

void	init_lookup(t_data *data)
{
	data->token_lookup = malloc(sizeof(char *) * (UNQUOTED + 1));
	if (data->token_lookup == NULL)
		free_exit(data, 1);
	data->token_lookup[HERE_DOC] = ft_strdup("<<");
	data->token_lookup[APPEND] = ft_strdup(">>");
	data->token_lookup[REDIR_IN] = ft_strdup("<");
	data->token_lookup[REDIR_OUT] = ft_strdup(">");
	data->token_lookup[VAR] = ft_strdup("$");
	data->token_lookup[SINGLE_QUOTED] = ft_strdup("'");
	data->token_lookup[DOUBLE_QUOTED] = ft_strdup("\"");
	data->token_lookup[UNQUOTED] = NULL;
}

