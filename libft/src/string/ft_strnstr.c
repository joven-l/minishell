/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:52:19 by joloo             #+#    #+#             */
/*   Updated: 2024/11/19 16:35:23 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (big == NULL && len == 0)
		return (NULL);
	if (little[0] == 0)
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i + ft_strlen(little) <= len)
	{
		if (ft_strncmp(big + i, little, ft_strlen(little)) == 0)
		{
			return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
/*#include <stdio.h>
#include <bsd/string.h>
int	main(void)
{
	//const char *big = "abcdefghi";
	const char *little = "a";
	//const char *little = NULL;
	//char big[5] = {'a','b','c','d','e'};
	char *big = NULL;
	size_t len = 0;
	printf("%s\n", strnstr(big, little, len));
	printf("%s\n", "a");
	printf("%s\n", ft_strnstr(big, little, len));
}*/
