/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:07:26 by joloo             #+#    #+#             */
/*   Updated: 2025/05/14 14:04:59 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_vstrjoin(int count, ...)
{
	va_list	args;
	int		i;
	char	**temp;
	char	*result;

	va_start(args, count);
	i = 0;
	temp = malloc(sizeof(char *) * (count + 1));
	if (temp == NULL)
		return (NULL);
	while (i < count)
	{
		temp[i] = va_arg(args, char *);
		i++;
	}
	temp[i] = NULL;
	result = ft_flatten(temp, NULL);
	free(temp);
	va_end(args);
	return (result);
}

// int	main(void)
// {
// 	char *s1 = ft_strdup("aaa");
// 	char *s2 = ft_strdup("bbbb");
// 	char *s3 = ft_strdup("ccc");
// 	char *s4 = ft_strdup("ddd");

// 	char *result = ft_vstrjoin(4, s1, s2, s3, s4);
// 	ft_printf("%s\n", result);
// 	free (result);
// 	free (s1);
// 	free (s2);
// 	free (s3);
// 	free (s4);
// }