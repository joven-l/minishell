/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:22:45 by joloo             #+#    #+#             */
/*   Updated: 2025/08/01 14:11:14 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_gnl	*find_fd_gnl(int fd, t_gnl **head)
{
	t_gnl	*temp;
	t_gnl	*new;

	temp = *head;
	while (temp != NULL)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	new = ft_calloc(1, sizeof(t_gnl));
	if (new == NULL)
		return (NULL);
	new->fd = fd;
	if (*head == NULL)
		*head = new;
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
	return (new);
}

static void	free_list_gnl(t_gnl *lst, t_gnl **head)
{
	t_gnl	*temp;

	if (lst == NULL || head == NULL || *head == NULL)
		return ;
	if (*head == lst)
	{
		*head = (*head)->next;
		free(lst->buffer);
		free(lst);
		return ;
	}
	temp = *head;
	while (temp->next != NULL && temp->next != lst)
		temp = temp->next;
	if (temp->next == lst)
	{
		temp->next = lst->next;
		free(lst->buffer);
		free(lst);
	}
}

static int	read_fd_gnl(t_gnl *curr)
{
	int	rc;

	rc = 0;
	while (1)
	{
		if (ft_strchr_pos(curr->buffer, '\n', curr->size) != 0)
			return (1);
		curr->buffer = ft_realloc(curr->buffer, 0,
				curr->size, curr->size + BUFFER_SIZE + 1);
		if (curr->buffer == NULL)
			return (0);
		rc = read(curr->fd, curr->buffer + curr->size, BUFFER_SIZE);
		if (rc == -1)
			return (0);
		curr->size += rc;
		curr->buffer[curr->size] = '\0';
		if (rc == 0)
		{
			curr->fd = -1;
			return (1);
		}
	}
}

static char	*extract_line_gnl(t_gnl *curr)
{
	int		len;
	char	*res;

	len = ft_strchr_pos(curr->buffer, '\n', curr->size);
	res = ft_substr(curr->buffer, 0, len);
	if (res == NULL)
		return (NULL);
	curr->size -= len;
	if (curr->size != 0)
	{
		curr->buffer = ft_realloc(curr->buffer, len,
				curr->size, curr->size + BUFFER_SIZE);
		if (curr->buffer == NULL)
		{
			free(res);
			return (NULL);
		}
	}
	return (res);
}

char	*get_next_line(int fd)
{
	char			*res;
	static t_gnl	*head;
	t_gnl			*curr;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	curr = find_fd_gnl(fd, &head);
	if (curr == NULL)
		return (NULL);
	if (read_fd_gnl(curr) == 0)
		return (free_list_gnl(curr, &head), NULL);
	res = extract_line_gnl(curr);
	if (res == NULL)
		return (free_list_gnl(curr, &head), NULL);
	if (curr->fd == -1)
		free_list_gnl(curr, &head);
	return (res);
}

// int main(void)
// {
// 	// int	fd;
// 	char *line;
// 	// int fd = open("test.txt", O_RDONLY);
// 	line = get_next_line(0);
// 	while (line != NULL)
// 	{
// 		printf("%s", line);
// 		free (line);
// 		line = get_next_line(0);
// 	}
// }
