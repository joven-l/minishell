/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:14:30 by joloo             #+#    #+#             */
/*   Updated: 2024/11/19 13:55:59 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *) s)[i] == (unsigned char) c)
		{
			return ((void *)((unsigned char *)s + i));
		}
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	const char *s = NULL;
	//const char *s = "BINGUS";
	int c = 0;
	size_t n = 1;
	//printf("%p\n", ft_memchr(s, c, n));
	//printf("%zu\n", ft_strlen(s) - ft_strlen(ft_memchr(s, c, n)));
	printf("%p\n", memchr(s, c, n));
	//printf("%zu\n", ft_strlen(s) - ft_strlen(memchr(s, c, n)));
}*/
