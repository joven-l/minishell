/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:25:12 by joloo             #+#    #+#             */
/*   Updated: 2025/07/27 20:16:35 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// counts the number of elemnts of an array
// not the length of the strings
size_t	ft_strarr_len(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
	{
		i++;
	}
	return (i);
}
