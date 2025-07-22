/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_basic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:10:10 by joloo             #+#    #+#             */
/*   Updated: 2025/04/18 13:42:15 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_char(va_list args)
{
	char	c;

	c = va_arg(args, int);
	ft_putchar_fd((char) c, 1);
	return (1);
}

int	ft_printf_str(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_printf_num(va_list args)
{
	int	num;
	int	i;

	i = 0;
	num = va_arg(args, int);
	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	ft_putnbr_fd(num, 1);
	if (num < 0)
		i++;
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int	ft_printf_unum(va_list args)
{
	unsigned int	num;
	int				i;

	i = 0;
	num = va_arg(args, unsigned int);
	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	ft_putunbr_fd(num, 1);
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int	ft_printf_perc(va_list args)
{
	(void)args;
	ft_putchar_fd('%', 1);
	return (1);
}
