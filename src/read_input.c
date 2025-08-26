/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:32:10 by joloo             #+#    #+#             */
/*   Updated: 2025/08/01 11:32:10 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ctrl + "d" return NULL
void	read_input(t_data *data)
{
	sigaction(SIGINT, &data->sig_inter, NULL);
	sigaction(SIGQUIT, &data->sig_inter, NULL);
	data->input = readline("minishell>");
	if (data->input == NULL)
		free_exit(data, 0);
	if (data->input != NULL)
		add_history(data->input);
	sigaction(SIGINT, &data->sig, NULL);
	sigaction(SIGQUIT, &data->sig, NULL);
}

