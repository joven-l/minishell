/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:31:14 by joloo             #+#    #+#             */
/*   Updated: 2025/08/12 11:31:14 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_exit(t_data *data, int exit_code)
{
	if (errno != 0)
		perror("Error");
	free(data->input);
	exit(exit_code);
}

void	free_prompt(t_data *data)
{
	if (errno != 0)
		perror("Error");
	free(data->input);
	data->input = NULL;
}
