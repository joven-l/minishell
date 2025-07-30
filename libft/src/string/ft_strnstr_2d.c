/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:13:15 by joloo             #+#    #+#             */
/*   Updated: 2025/04/17 13:38:49 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns the full string if matches little, not only after the match
// arrlen is how many arrays to search
// len is how many character to search
char	*ft_strnstr_2d(char **big, char *little, size_t arrlen, size_t len)
{
	size_t	i;

	i = 0;
	while (big[i] != NULL && i < arrlen)
	{
		if (ft_strnstr(big[i], little, len) != NULL)
		{
			return ((char *)big[i]);
		}
		i++;
	}
	return (NULL);
}
