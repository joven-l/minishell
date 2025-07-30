/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subarr_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:51:46 by joloo             #+#    #+#             */
/*   Updated: 2025/07/10 14:16:46 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// making a smaller 2d array from a bigger 2d array
// only free result, not result[i] as its still pointing to original str
// mainly for use with argv
char	**ft_subarr_str(char **str, int start, int len)
{
	char	**result;
	int		i;

	result = malloc(sizeof(char *) * (len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = str[i + start];
		i++;
	}
	result[i] = NULL;
	return (result);
}
