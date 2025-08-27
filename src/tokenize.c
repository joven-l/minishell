/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:06:04 by joloo             #+#    #+#             */
/*   Updated: 2025/08/01 15:06:04 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// i = start
// j = unquoted len
int	tokenize(t_data *data)
{
	int	i;
	int	type;

	i = 0;
	while (data->input[i] != '\0')
	{
		while (data->input[i] != '\0' && data->input[i] == ' ')
			i++;
		if (data->input[i] == '\0')
			break ;
		type = detect_operator(data, i);
		if (type == UNQUOTED)
		{
			if (add_unquoted(data, &i) == 0)
				return (0);
		}
		else
		{
			if (add_operator(data, &i, type) == 0)
				return (0);
		}
	}
	return (1);
}

int detect_operator(t_data *data, int i)
{
	int	type;

	type = 0;
	while (data->token_lookup[type] != NULL)
	{
		if (ft_strncmp(data->input + i, data->token_lookup[type], 
		 ft_strlen(data->token_lookup[type])) == 0)
			return (type);
		type++;
	}
	return (UNQUOTED);
}

void	add_node(t_data *data, int start, int len, int type)
{
	t_token	*node;

	node = ft_calloc(1, sizeof(t_token));
	if (node == NULL)
		free_exit(data, 1);
	node->content = ft_substr(data->input, start, len);
	if (node->content == NULL)
		free_exit(data, 1);
	node->type = type;
	if (data->token == NULL)
	{
		data->token = node;
		data->token_last = node;
	}
	else
	{
		data->token_last->next = node;
		node->prev = data->token_last;
		data->token_last = node;
	}
}
