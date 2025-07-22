/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:52:29 by joloo             #+#    #+#             */
/*   Updated: 2024/11/15 15:51:56 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

/*#include <bsd/string.h>
int	main(void)
{
	char dst[10] = "aaa\0";
	char dst2[10] = "aaa\0";
	//char *src = "";
	//char *src2 = "qwerty";
	size_t size = 15;
	ft_strlcpy(dst, "lore\0m ipsum dolor sit amet", size);
	printf("%s\n",dst);
	strlcpy(dst2, "lore\0m ipsum dolor sit amet", size);
	printf("%s\n",dst2);
}*/
