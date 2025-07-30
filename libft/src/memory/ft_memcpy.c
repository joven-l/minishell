/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:35:42 by joloo             #+#    #+#             */
/*   Updated: 2024/12/02 17:46:19 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *) dest)[i] = ((unsigned char *) src)[i];
		i++;
	}
	return (dest);
}
// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	//char *dest = NULL;
// 	//const char *src = NULL;
//     char dest[] = "ermmm";
// 	//char src[] = "aaaa";
//     //const char *src = dest + 1;
// 	//char *dest2 = ft_strdup(dest);
// 	//ft_memcpy(dest, src, 4);
// 	//memcpy(dest, dest + 2, 2);
//     ft_memcpy(dest, dest + 2, 2);
//     //memcpy(dest, src, 4);
// 	printf("%s\n", dest);
// 	//printf("%s\n", dest2);
// }