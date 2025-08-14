/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:03:32 by joloo             #+#    #+#             */
/*   Updated: 2025/08/11 12:15:11 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

// memory
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_realloc(void *ptr, int start, int old_size, int new_size);
void	ft_free_str_arr(char **arr);
void	ft_free_int_arr(int **arr);
void	ft_free_3d_arr(char ***arr);

// number
int		ft_abs_diff(int a, int b);
int		*ft_intdup(int *arr, int size);
int		ft_intlen(int n);
void	ft_sort_int_tab(int *tab, int size);
void	ft_swap(int *a, int *b);
int		ft_valid_int(const char *str);

// char
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_isspace(int s);

// conversion
int		*ft_atoi_array(char **split, int size);
char	**ft_itoa_array(int *arr, int size);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);

// string
int		ft_count_char(char *str, char c);
size_t	count_words(char const *s, char c);
char	*ft_flatten(char **arr, char *str);
size_t	ft_strlen(const char *s);
size_t	ft_strarr_len(char **arr);
size_t	ft_strarr_strlen(char **arr);
char	**ft_strarrdup(char **arr);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_subarr_str(char **str, int start, int len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strnstr_2d(char **big, char *little, size_t arrlen, size_t len);
int		ft_strchr_pos(const char *str, int c, int size);
void	ft_strrev(char *result);

// io
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putunbr_fd(unsigned int n, int fd);
int		ft_putnbr_base(int nbr, char *base, int count);
int		ft_putunbr_base(unsigned int nbr, char *base, int count);
void	ft_putunbr_fd(unsigned int n, int fd);
int		ft_putlong_base(unsigned long nbr, char *base, int count);

// lists
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// get_next_line
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

typedef struct s_gnl
{
	int				fd;
	int				size;
	char			*buffer;
	struct s_gnl	*next;
}					t_gnl;
char	*get_next_line(int fd);

// printf
// int		ft_printf(const char *format, ...);
// int		ft_printf_char(va_list args);
// int		ft_printf_str(va_list args);
// int		ft_printf_num(va_list args);
// int		ft_printf_unum(va_list args);
// int		ft_printf_perc(va_list args);
// int		ft_printf_ptr(va_list args);
// int		ft_printf_hex(va_list args);
// int		ft_printf_hex_upper(va_list args);
// int		ft_printf_str_arr(va_list args);
// int		ft_printf_gnl(va_list args);
// char	*ft_vstrjoin(int count, ...);

#endif
