/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_strlen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:01:40 by joloo             #+#    #+#             */
/*   Updated: 2025/03/11 14:20:33 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ft_strlen but for a whole array
size_t	ft_strarr_strlen(char **arr)
{
	size_t	i;
	size_t	count;
	size_t	j;

	i = 0;
	count = 0;
	while (arr[i] != NULL)
	{
		j = 0;
		while (arr[i][j] != '\0')
		{
			count++;
			j++;
		}
		i++;
	}
	return (count);
}
