/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:22:06 by joloo             #+#    #+#             */
/*   Updated: 2025/03/05 14:41:36 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *result)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = ft_strlen(result) - 1;
	if (result[start] == '-')
		start++;
	while (start < end)
	{
		temp = result[start];
		result[start] = result[end];
		result[end] = temp;
		start++;
		end--;
	}
}

static void	fill(char *result, int n)
{
	int	i;
	int	j;

	i = 0;
	j = ft_intlen(n);
	if (n < 0)
	{
		result[i] = '-';
		i++;
		n *= -1;
	}
	while (i < j)
	{
		result[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	result[i] = '\0';
	ft_strrev(result);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*result;

	len = ft_intlen(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == 2147483647)
		return (ft_strdup("2147483647"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	result = malloc(sizeof(char) * len + 1);
	if (result == NULL)
		return (NULL);
	fill(result, n);
	return (result);
}

/*int	main(void)
{
	printf("%s\n", ft_itoa(-123123));
	printf("%s\n", ft_itoa(-10));
}*/
