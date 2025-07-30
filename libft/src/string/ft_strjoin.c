/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:48:31 by joloo             #+#    #+#             */
/*   Updated: 2025/03/06 16:01:59 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// s2 added to the end of s1
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*result;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	result = malloc(sizeof(char) * (s1len + s2len + 1));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, s1len + 1);
	ft_strlcat(result, s2, s1len + s2len + 1);
	return (result);
}

/*int	main(void)
{
	char const *s1 = "aaa";
	char const *s2 = "bbb";
	printf("%s\n", ft_strjoin(s1,s2));
}*/
