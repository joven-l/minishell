/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:31:12 by joloo             #+#    #+#             */
/*   Updated: 2025/05/06 16:35:39 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// does not account for invalid input, use ft_valid_int for that
int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	isneg;

	i = 0;
	result = 0;
	isneg = 1;
	while (ft_isspace(nptr[i]) == 1)
	{
		i++;
	}
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			isneg *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]) == 1)
	{
		result *= 10;
		result += (nptr[i] - '0');
		i++;
	}
	result *= isneg;
	return (result);
}

/*int	main(void)
{
	const char *nptr = "-0";
	//char *nptr = NULL;
	printf("%d\n", ft_atoi(nptr));
	printf("%d\n", atoi(nptr));
}*/
