/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:55:35 by joloo             #+#    #+#             */
/*   Updated: 2025/08/01 13:55:35 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// SIGINT = ctrl + "c"
// SIGQUIT = ctrl + "\"
void	handler_inter(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1); 
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	handler(int sig)
{
	(void)sig;
}
