/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:14:41 by joloo             #+#    #+#             */
/*   Updated: 2024/11/24 13:11:08 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	slen;

	slen = ft_strlen(s);
	result = malloc(sizeof(char) * (slen + 1));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s, slen + 1);
	return (result);
}
/*int	main(void)
{
    const char *original = "av   a 12340832572918045";
    char *copy = ft_strdup(original);
	if (copy == NULL)
	{
		printf("%s", "bruh");
		return (1);
	}
	printf("%s", copy);
	free(copy);
}*/
