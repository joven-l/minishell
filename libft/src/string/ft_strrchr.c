/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:00:12 by joloo             #+#    #+#             */
/*   Updated: 2024/11/30 13:13:49 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			j = i;
		}
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	if (j == 0 && s[j] != (char)c)
		return (NULL);
	return ((char *)s + j);
}

/*int	main(void)
{
	const char *s = "ab";
	//const char *s = NULL;
	//int c = 'a';
	int c = '\0';
	printf("%ld\n", strrchr(s, c) - s);
	printf("%ld\n", ft_strrchr(s, c) - s);
}*/
