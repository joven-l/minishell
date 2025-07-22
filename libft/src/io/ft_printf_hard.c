/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:57:45 by joloo             #+#    #+#             */
/*   Updated: 2025/04/30 15:43:05 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_ptr(va_list args)
{
	void				*temp;
	unsigned long		ptr;
	int					i;

	i = 0;
	temp = va_arg(args, void *);
	ptr = (unsigned long) temp;
	if (ptr == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	i += (ft_putlong_base(ptr, "0123456789abcdef", 0) + 2);
	return (i);
}

int	ft_printf_hex(va_list args)
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
	i += ft_putunbr_base(num, "0123456789abcdef", 0);
	return (i);
}

int	ft_printf_hex_upper(va_list args)
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
	i += ft_putunbr_base(num, "0123456789ABCDEF", 0);
	return (i);
}
// includes a \n after every line

int	ft_printf_str_arr(va_list args)
{
	char	**str;
	int		i;
	int		count;

	str = va_arg(args, char **);
	i = 0;
	count = 0;
	while (str[i] != NULL)
	{
		if (str[i] == NULL)
		{
			ft_putstr_fd("(null)", 1);
			count += 6;
		}
		ft_putstr_fd(str[i], 1);
		ft_putstr_fd("\n", 1);
		count += ft_strlen(str[i]) + 1;
		i++;
	}
	return (count);
}

int	ft_printf_gnl(va_list args)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = va_arg(args, int);
	line = get_next_line(fd);
	while (line != NULL)
	{
		count += ft_strlen(line);
		ft_putstr_fd(line, 1);
		free(line);
		line = get_next_line(fd);
	}
	return (count);
}
