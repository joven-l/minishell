/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 10:25:32 by joloo             #+#    #+#             */
/*   Updated: 2025/08/18 10:25:32 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_exit(t_data *data, int exit_code)
{
	if (errno != 0)
		perror("Error");
	free_tokens(data);
	free(data->input);
	data->input = NULL;
	exit(exit_code);
}

void	free_prompt(t_data *data)
{
	if (errno != 0)
		perror("Error");
	free_tokens(data);
	free(data->input);
	data->input = NULL;
}

void	free_tokens(t_data *data)
{
	t_token	*node;
	t_token *temp;

	node = data->token;
	while (node != NULL)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
	data->token = NULL;
}
