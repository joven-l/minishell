/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:34:36 by joloo             #+#    #+#             */
/*   Updated: 2024/11/19 17:11:03 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1c;
	unsigned char	*s2c;

	if (n == 0)
		return (0);
	s1c = (unsigned char *) s1;
	s2c = (unsigned char *) s2;
	i = 0;
	while (s1c[i] == s2c[i] && i < n - 1)
	{
		i++;
	}
	return (s1c[i] - s2c[i]);
}

/*int	main(void)
{
	//const char *s1 = "abcdef'\0'a";
	//const char *s2 = "abcdef'\0'z";
	char *s1 = NULL;
	char *s2 = NULL;
	size_t n = 0;
	printf("%d\n", ft_memcmp(s1, s2, n));
	printf("%d\n", memcmp(s1, s2, n));
}*/
