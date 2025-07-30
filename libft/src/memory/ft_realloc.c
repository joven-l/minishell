/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:57:40 by joloo             #+#    #+#             */
/*   Updated: 2025/07/24 12:16:25 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// modifying memory to have more size but contents remain the same
// does not auto null terminate
// frees the old buffer for you
void	*ft_realloc(void *ptr, int start, int old_size, int new_size)
{
	void	*res;
	int		i;

	if (new_size == 0)
		return (free(ptr), NULL);
	res = malloc(new_size);
	if (res == NULL)
		return (NULL);
	if (ptr != NULL)
	{
		i = 0;
		while (i < new_size && i < old_size - start)
		{
			((unsigned char *) res)[i] = ((unsigned char *) ptr)[start + i];
			i++;
		}
		free(ptr);
	}
	return (res);
}

// int	main(void)
// {
// 	char	*str = NULL;

// 	str = ft_realloc(str, 0, 0, 5);
// 	str[4] = '\0';
// 	str[0] = 'a';
// 	str[1] = 'a';
// 	str[2] = 'a';
// 	str[3] = 'a';
// 	printf("%s\n", str);
// 	str = ft_realloc(str, 1, 5, 10);
// 	printf("%s\n", str);
// }
