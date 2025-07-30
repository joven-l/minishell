/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:06:57 by joloo             #+#    #+#             */
/*   Updated: 2024/11/24 12:55:24 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	if (nmemb == 0 || size == 0)
	{
		result = malloc(1);
		if (result == NULL)
			return (NULL);
		return (result);
	}
	if (nmemb > (size_t) -1 / size)
		return (NULL);
	result = malloc(nmemb * size);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, nmemb * size);
	return (result);
}

/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	size_t a = 0;
	size_t b = 0;
	char *c;

	c = ft_calloc(a, b);
	//c = calloc(a, b);
	if (c == NULL)
		printf("%s", "a");
	size_t size = 0;

	char *d1 = ft_calloc(size, 10);
	char *d2 = calloc(size, 10);
	if (memcmp(d1, d2, 1 * sizeof(int)))
		printf("%s\n", "fail");
	printf("%p\n", d1);
	printf("%p\n", d2);
	free(d1);
	free(d2);
	printf("%s\n", "win");
}*/
