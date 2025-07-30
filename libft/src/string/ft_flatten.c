/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flatten.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:11:19 by joloo             #+#    #+#             */
/*   Updated: 2025/05/26 16:06:06 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// makes a 2d char array into 1d
// char *str is an optional delimiter between elements
char	*ft_flatten(char **arr, char *str)
{
	int		i;
	char	*result;
	int		len;

	i = 0;
	len = ft_strarr_strlen(arr);
	if (str != NULL)
		len += (ft_strarr_len(arr) - 1) * ft_strlen(str);
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	result[0] = '\0';
	while (arr[i] != NULL)
	{
		ft_strlcat(result, arr[i], len + 1);
		if (str != NULL && arr[i + 1] != NULL)
		{
			ft_strlcat(result, str, len + 1);
		}
		i++;
	}
	return (result);
}
