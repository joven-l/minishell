/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:06:17 by joloo             #+#    #+#             */
/*   Updated: 2025/05/09 16:08:52 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// duplicates an integer array
int	*ft_intdup(int *arr, int size)
{
	int	i;
	int	*result;

	if (size < 1)
		return (0);
	i = 0;
	result = malloc(sizeof(int) * size);
	if (result == NULL)
		return (0);
	while (i < size)
	{
		result[i] = arr[i];
		i++;
	}
	return (result);
}
