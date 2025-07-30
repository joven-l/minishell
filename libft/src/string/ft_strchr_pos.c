/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:16:55 by joloo             #+#    #+#             */
/*   Updated: 2025/04/23 17:03:53 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// better strchr, returns the index + 1 rather than pointer
// if at [0] return 1
// 0 is NULL/not found
int	ft_strchr_pos(const char *str, int c, int len)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (i < len)
	{
		if (str[i] == (char)c)
		{
			return (i + 1);
		}
		i++;
	}
	if ((char)c == '\0')
		return (i + 1);
	return (0);
}
