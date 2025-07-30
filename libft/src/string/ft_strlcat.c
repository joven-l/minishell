/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:12:05 by joloo             #+#    #+#             */
/*   Updated: 2025/03/11 14:40:10 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size should be the full size of dst
// size - dlen - 1 being how much src should copy
// size must + 1 for full copy
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;

	if (size == 0)
		return (ft_strlen(src));
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (size > dlen)
		ft_strlcpy(dst + dlen, src, size - dlen);
	else
		return (slen + size);
	return (slen + dlen);
}
/*#include <stdio.h>
#include <bsd/string.h>
int	main(void)
{
	//const char src[10] = "abcde";
	char *src = "";
    char dst[30] = "abcdefghi";
	char dst2[30] = "abcdefghi";
	//char *dst = (void*)0;
	//char *dst2 = (void*)0;
    size_t size = 12;
	//char b[0xF] = "nyan !";
	//char b2[0xF] = "nyan !";
	
	printf("%s\n", "reached");
    printf("%lu\n",strlcat(dst, src, size));
    printf("%s\n", dst);
	printf("%lu\n", ft_strlcat(dst2, src, size));
	printf("%s\n", dst2);
}*/
