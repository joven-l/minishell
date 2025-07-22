/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:44:26 by joloo             #+#    #+#             */
/*   Updated: 2025/05/26 16:04:08 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// checks if char * can be an integer within int_max and int_min
static int	check_number(const char *str, int isneg)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	if (ft_strlen(str) > 10)
		return (0);
	if (ft_strlen(str) == 10)
	{
		if (isneg == -1)
		{
			if (ft_strncmp(str, "2147483648", 10) > 0)
				return (0);
		}
		else
		{
			if (ft_strncmp(str, "2147483647", 10) > 0)
				return (0);
		}
	}
	return (1);
}

int	ft_valid_int(const char *str)
{
	int	i;
	int	isneg;

	i = 0;
	isneg = 1;
	while (ft_isspace(str[i]) == 1)
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			isneg *= -1;
		i++;
	}
	if (ft_isdigit(str[i]) == 0)
		return (0);
	while (str[i] == '0')
		i++;
	return (check_number(str + i, isneg));
}

// int	main(void)
// {
// 	printf("%d\n", ft_valid_int(ft_strdup("0002147483647")));
// 	printf("%d\n", ft_valid_int(ft_strdup("0002147483648")));
// 	printf("%d\n", ft_valid_int(ft_strdup("-0002147483648")));
// 	printf("%d\n", ft_valid_int(ft_strdup("-0002147483649")));
// 	printf("%d\n", ft_valid_int("00"));
// 	printf("%d\n", ft_valid_int("-010"));
// 	printf("%d\n", ft_valid_int(""));	
// }
