/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:22:45 by joloo             #+#    #+#             */
/*   Updated: 2025/04/30 15:27:09 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gnl	*find_fd_gnl(int fd, t_gnl **lst)
{
	t_gnl	*temp;
	t_gnl	*last;
	t_gnl	*new;

	temp = *lst;
	while (temp != NULL)
	{
		if (temp -> fd == fd)
			return (temp);
		last = temp;
		temp = temp -> next;
	}
	new = malloc(sizeof(t_gnl));
	if (new == NULL)
		return (NULL);
	new -> fd = fd;
	new -> size = 0;
	new -> buffer = NULL;
	new -> next = NULL;
	if (*lst == NULL)
		*lst = new;
	else
		last -> next = new;
	return (new);
}

char	*extract_line_gnl(t_gnl *lst)
{
	char	*result;
	int		i;

	if (lst -> fd == -1)
		i = lst -> size;
	else
		i = find_nl_gnl(lst);
	result = ft_substr_gnl(lst -> buffer, 0, i);
	if (result == NULL)
	{
		free(lst -> buffer);
		lst -> buffer = NULL;
		lst -> fd = -1;
		return (NULL);
	}
	lst -> size -= i;
	ft_realloc_gnl(&lst -> buffer, i, lst -> size, lst-> size);
	if (lst -> buffer == NULL)
	{
		lst -> fd = -1;
		return (NULL);
	}
	return (result);
}

int	read_fd_gnl(t_gnl *lst, int fd)
{
	int	rc;

	rc = 1;
	while (rc > 0 && find_nl_gnl(lst) == 0)
	{
		ft_realloc_gnl(&lst -> buffer, 0,
			lst-> size, lst -> size + BUFFER_SIZE);
		if (lst -> buffer == NULL)
		{
			lst -> fd = -1;
			return (0);
		}
		rc = read(fd, lst -> buffer + lst -> size, BUFFER_SIZE);
		if (rc == -1)
		{
			free(lst -> buffer);
			lst -> buffer = NULL;
			lst -> fd = -1;
			return (0);
		}
		lst -> size += rc;
	}
	if (rc == 0)
		lst -> fd = -1;
	return (1);
}

char	*get_next_line(int fd)
{
	char			*result;
	static t_gnl	*lst;
	t_gnl			*current;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	current = find_fd_gnl(fd, &lst);
	if (current == NULL)
		return (NULL);
	if (read_fd_gnl(current, fd) == 0 && current -> fd == -1)
	{
		free_list_gnl(current, &lst);
		return (NULL);
	}
	result = extract_line_gnl(current);
	if (result == NULL)
	{
		free_list_gnl(current, &lst);
		return (NULL);
	}
	if (current -> fd == -1)
		free_list_gnl(current, &lst);
	return (result);
}

// int main(void)
// {
// 	// int	fd;
// 	char *line;
// 	// int fd = open("test.txt", O_RDONLY);
// 	line = get_next_line(0);
// 	while (line != NULL)
// 	{
// 		if (line[0] == '\n')
// 		{
// 			free (line);
// 			break;
// 		}
// 		printf("%s", line);
// 		free (line);
// 		line = get_next_line(0);
// 	}
// 	// fd = open("here_doc_tmp.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
// 	// if (fd == -1)
// 	// 	printf("%s\n", "fail");
// 	// line = get_next_line(0);
// 	// ft_printf("%d\n", check_limiter("end", line));
// 	// while (line != NULL && check_limiter("end", line) != 1)
// 	// {
// 	// 	ft_printf("line:%s\n", line);
// 	// 	write(fd, line, ft_strlen(line));
// 	// 	free (line);
// 	// 	line = get_next_line(0);
// 	// }
// 	// ft_printf("end:%s\n", line);
// 	// if (line != NULL)
// 	// 	free (line);
// 	// close(fd);
// 	// int fd2;
// 	// ft_printf("%s\n", "opening");
// 	// fd2 = open("here_doc_tmp.txt", O_RDONLY);
// 	// if (fd2 == -1)
// 	// 	printf("%s\n", "fail");
// 	// ft_printf("%f", fd2);
// 	return (0);
// }
