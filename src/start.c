/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:12:39 by joloo             #+#    #+#             */
/*   Updated: 2025/07/27 19:12:39 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	start(t_data *data)
{
	int	rs;
	while (1)
	{
		read_input(data);
		rs = tokenize(data);
		printf("%d\n", rs);
		if (rs == 0)
			continue ;
		t_token *tmp;
		tmp = data->token;
		while (tmp != NULL)
		{
			printf("%s\n", tmp->content);
			tmp = tmp->next;
		}
	}
}
