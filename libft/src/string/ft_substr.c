/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:37:36 by joloo             #+#    #+#             */
/*   Updated: 2025/04/23 17:19:56 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;

	if (len == 0)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
	{
		result = malloc(sizeof(char) * (ft_strlen(s + start) + 1));
		if (result == NULL)
			return (NULL);
	}
	else
	{
		result = malloc(sizeof(char) * (len + 1));
		if (result == NULL)
			return (NULL);
	}
	ft_strlcpy(result, s + start, len + 1);
	return (result);
}

/*int	main(void)
{
	char const *s = "bingus";
	unsigned int start = 2;
	size_t len = 10;
	char * result;
	result = ft_substr(s,start,len);
	printf("%s", result);	
}*/
