/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:22:59 by joloo             #+#    #+#             */
/*   Updated: 2025/04/30 13:39:46 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_nl_gnl(t_gnl *lst)
{
	int	i;

	if (lst->buffer == NULL || lst->size == 0)
		return (0);
	i = 0;
	while (i < lst -> size)
	{
		if (lst -> buffer[i] == '\n')
		{
			return (i + 1);
		}
		i++;
	}
	return (0);
}

char	*ft_substr_gnl(char *buffer, int start, int len)
{
	char	*result;
	int		i;

	if (len == 0)
		return (NULL);
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
	{
		free (buffer);
		buffer = NULL;
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		result[i] = buffer[i + start];
		i++;
	}
	result[i] = '\0';
	return (result);
}

void	ft_realloc_gnl(char **buffer, int start, int old_size, int new_size)
{
	char	*newbuf;
	int		i;

	newbuf = malloc(sizeof(char) * (new_size + 1));
	if (newbuf == NULL)
	{
		free (*buffer);
		*buffer = NULL;
		return ;
	}
	i = 0;
	if (*buffer != NULL)
	{
		while (i < old_size && i < new_size)
		{
			newbuf[i] = (*buffer)[i + start];
			i++;
		}
		free(*buffer);
	}
	newbuf[i] = '\0';
	*buffer = newbuf;
}

void	free_list_gnl(t_gnl *lst, t_gnl **head)
{
	t_gnl	*temp;

	if (lst == NULL)
		return ;
	temp = *head;
	if (*head == lst)
		*head = lst -> next;
	else
	{
		while (temp -> next != lst && temp != NULL)
			temp = temp -> next;
		if (temp != NULL)
			temp -> next = lst -> next;
	}
	if (lst -> buffer != NULL)
		free (lst -> buffer);
	free (lst);
}
