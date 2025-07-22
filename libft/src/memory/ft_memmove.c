/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:40:38 by joloo             #+#    #+#             */
/*   Updated: 2024/11/20 12:05:35 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d > s)
	{
		i = n;
		while (i > 0)
		{
			i--;
			ft_memcpy(d + i, s + i, 1);
		}
	}
	else
	{
		ft_memcpy(d, s, n);
	}
	return (dest);
}
/*#include <string.h>
#include <stdio.h>
int	main(void)
{
	//char *dest = NULL;
	//const char *src = "qwerty";
	void *dest = NULL;
    const void *src = NULL;
	//char *dest2 = ft_strdup(dest);
	//char *dest3 = ft_strdup(dest);
	//ft_memmove(dest, dest, 0);
	//memmove(dest, dest, 3);
	ft_memmove(dest, src, 5);
	//memmove(dest, src, 5);
	//printf("%s\n", dest2);
	//printf("%s\n", dest3);
}*/
