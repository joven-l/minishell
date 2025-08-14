/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:32:03 by joloo             #+#    #+#             */
/*   Updated: 2025/08/12 10:32:03 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int handle_operator(t_data *data, int *i, int type)
{
	if (type == SINGLE_QUOTED)
		return (SINGLE_QUOTED);
	else if (type == DOUBLE_QUOTED)
		return (DOUBLE_QUOTED);
	add_node(data, *i , ft_strlen(data->token_lookup[type]), type);
	*i += ft_strlen(data->token_lookup[type]);
	return (1);
}

int	handle_squote(t_data *data, int *i)
{
	int	j;

	if (data->input[*i] != '\'')
		return (0);
	j = ft_strchr_pos(data->input + *i + 1, '\'', ft_strlen(data->input + *i));
	if (j == 0)
		return (printf("Unclosed quotes"), free_prompt(data), 0);
	add_node(data, *i, j, SINGLE_QUOTED);
	*i += j;
	return (1);
}

int	handle_dquote(t_data *data, int *i)
{
	int	j;

	if (data->input[*i] != '"')
		return (0);
	j = ft_strchr_pos(data->input + *i + 1, '"', ft_strlen(data->input + *i));
	if (j == 0)
		return (printf("Unclosed quotes"), free_prompt(data), 0);
	add_node(data, *i, j, DOUBLE_QUOTED);
	*i += j;
	return (1);
}

int	handle_unquote(t_data *data, int *i)
{
	int	j;
}
