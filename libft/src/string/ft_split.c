/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:28:19 by joloo             #+#    #+#             */
/*   Updated: 2025/05/09 18:39:11 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	fill(char **result, char const *s, char c, size_t index)
{
	size_t	j;

	if (ft_strchr(s, c) != NULL)
	{
		j = ft_strlen(s) - ft_strlen(ft_strchr(s, c));
	}
	else
	{
		j = ft_strlen(s);
	}
	result[index] = malloc(sizeof(char) * (j + 1));
	if (result[index] == NULL)
		return (0);
	ft_strlcpy(result[index], s, j + 1);
	return (j);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	index;
	char	**result;

	i = 0;
	index = 0;
	result = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (result == NULL)
		return (NULL);
	while (index < count_words(s, c))
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		i += fill(result, s + i, c, index);
		if (result[index] == NULL)
		{
			ft_free_str_arr(result);
			return (NULL);
		}
		index++;
	}
	result[index] = NULL;
	return (result);
}

/*#include <stdio.h>
int	main(void)
{
	char const *s = "iabcdefiiiqwertyiibongusiiiiiibongusi";
	char c = 'i';
	int i = 0;
	int j = count_words(s, c) + 1;
	char **split = ft_split(s, c);
	printf("countword + 1: ""%zu\n", count_words(s,c) + 1);
	while (i < j)
	{
		printf("%s\n", split[i]);
		i++;
	}
	printf("%s\n", split[i]);
}*/
