/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:09:25 by joloo             #+#    #+#             */
/*   Updated: 2024/11/19 12:10:49 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *) s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/*#include <stdio.h>
int	main(void)
{
	char *s1 = NULL;
	char *s2 = NULL;
	//char *s = NULL;
	//char *s1 = ft_strdup(s);
	//char *s2 = ft_strdup(s);
	int c = 'a';
	size_t n = 0;
	printf("%s\n", "TESTING");
	memset(s1, c, n);
	printf("%s\n", s1);
	ft_memset(s2, c, n);
	printf("%s\n", s2);
}*/
