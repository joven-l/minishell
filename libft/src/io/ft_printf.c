/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:36:37 by joloo             #+#    #+#             */
/*   Updated: 2025/04/18 14:13:49 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	**conv(void)
{
	void	**ft;

	ft = ft_calloc(128, sizeof(void *));
	if (ft == NULL)
		return (NULL);
	ft['c'] = ft_printf_char;
	ft['s'] = ft_printf_str;
	ft['p'] = ft_printf_ptr;
	ft['d'] = ft_printf_num;
	ft['i'] = ft_printf_num;
	ft['u'] = ft_printf_unum;
	ft['x'] = ft_printf_hex;
	ft['X'] = ft_printf_hex_upper;
	ft['%'] = ft_printf_perc;
	ft['S'] = ft_printf_str_arr;
	ft['f'] = ft_printf_gnl;
	return (ft);
}

static int	do_conv(va_list args, void **ft, const char *format, int i)
{
	int		(*func)(va_list);
	int		len;

	len = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (ft[(int)format[i]] != NULL)
			{
				func = ft[(int)format[i]];
				len += func(args);
			}
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			len++;
		}
		i++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	void	**ft;
	int		len;
	int		i;

	len = 0;
	i = 0;
	ft = conv();
	if (ft == NULL)
		return (0);
	va_start(args, format);
	len += do_conv(args, ft, format, i);
	va_end(args);
	free (ft);
	return (len);
}
