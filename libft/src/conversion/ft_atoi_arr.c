/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:25:24 by joloo             #+#    #+#             */
/*   Updated: 2025/03/13 16:38:20 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// atoi but from 2d char array to 1d int array
// use along with gnl and ft_split

int	*ft_atoi_array(char **split, int size)
{
	int	*arr;
	int	i;

	i = 0;
	arr = malloc(sizeof(int) * (size));
	if (arr == NULL)
		return (0);
	while (i < size)
	{
		arr[i] = ft_atoi(split[i]);
		i++;
	}
	return (arr);
}
