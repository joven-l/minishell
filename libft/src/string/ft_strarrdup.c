/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:13:02 by joloo             #+#    #+#             */
/*   Updated: 2025/07/27 20:16:46 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// makes a copy of 2d array
// need to free all
char	**ft_strarrdup(char **arr)
{
	char	**result;
	int		i;

	result = malloc(sizeof(char *) * (ft_strarr_len(arr) + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (arr[i] != NULL)
	{
		result[i] = ft_strdup(arr[i]);
		if (result[i] == NULL)
		{
			ft_free_str_arr(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
