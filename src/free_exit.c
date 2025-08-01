/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 17:14:34 by joloo             #+#    #+#             */
/*   Updated: 2025/07/27 17:14:34 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_exit(t_data *data, int exit_code)
{
	if (errno != 0)
		perror("Error");
	free (data->input);
	exit(exit_code);
}
