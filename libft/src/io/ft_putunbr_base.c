/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:45:22 by joloo             #+#    #+#             */
/*   Updated: 2025/04/18 19:33:09 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_base_len(char *base)
{
	int	j;
	int	i;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	ft_putunbr_base(unsigned int nbr, char *base, int count)
{
	char				a;
	unsigned int		len;

	len = get_base_len(base);
	if (len == 0)
		return (0);
	if (nbr > len - 1)
	{
		count = ft_putunbr_base(nbr / len, base, count);
	}
	a = base[nbr % len];
	ft_putchar_fd(a, 1);
	count++;
	return (count);
}
