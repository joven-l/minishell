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
	data->token_lookup = malloc(sizeof(char *) * (10 + 1));
	if (data->token_lookup == NULL)
		free_exit(data, 1);
	data->token_lookup[
}

