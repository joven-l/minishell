/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:54:57 by joloo             #+#    #+#             */
/*   Updated: 2024/11/30 13:14:02 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}

/*int	main(void)
{
	//char *s = "abcdef";
	//char s[5] = {'a', 'b', 'c', 'd', 'e'};
	char *s = NULL;
	int c = 'v';
	//int c = '\0';
	printf("%s\n", ft_strchr(s, c));
	printf("%zu\n", ft_strlen(s) - ft_strlen(ft_strchr(s, c)));
	printf("%s\n", strchr(s, c));
	printf("%zu\n", ft_strlen(s) - ft_strlen(strchr(s, c)));
}*/
