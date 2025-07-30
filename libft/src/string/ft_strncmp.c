/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:57:20 by joloo             #+#    #+#             */
/*   Updated: 2025/04/23 16:49:00 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0') && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)s1[i] - ((unsigned char )s2[i]));
}

/*int	main(void)
{
	//const char *s1 = "test\200";
	const char *s2 = "test\0";
    	const char *s1 = NULL;
    //const char *s2 = NULL;
	size_t n = 2;
	printf("%s\n", "reched");
	printf("%d", ft_strncmp(s1,s2,n));
	printf("%d", strncmp(s1, s2, n));
}*/
