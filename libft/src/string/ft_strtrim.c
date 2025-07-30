/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:31:55 by joloo             #+#    #+#             */
/*   Updated: 2024/11/17 15:36:33 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	inset(char const s, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (s == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*result;

	if (s1[0] == 0)
		return (ft_strdup(""));
	i = 0;
	j = ft_strlen(s1);
	len = j;
	while (inset(s1[i], set) == 1)
		i++;
	while (inset(s1[j - 1], set) == 1)
		j--;
	if (j <= i)
		return (ft_strdup(""));
	len = len - ((len - j) + i);
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1 + i, len + 1);
	return (result);
}

/*int	main(void)
{
	char const *s1 = "  aaabc123aGGaGGcbaba a ";
	char const *set = "abc ";
	printf("%s", ft_strtrim(s1, set));
}*/
