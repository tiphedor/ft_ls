/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:28:37 by msteffen          #+#    #+#             */
/*   Updated: 2018/03/07 13:44:05 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

# define FT_LIBFT 1
# define FT_VERSION 1
# define BUFF_SIZE 60

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

size_t			ft_strlen(const char *str);
int				ft_strcmp(const char *sstr1, const char *sstr2);
int				ft_strncmp(const char *sstr1, const char *sstr2, size_t num);

int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_toupper(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_tolower(int c);
int				ft_intlen(unsigned int n);

int				ft_isoneof(char c, const char *str);

void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
int				ft_memcmp(const void *ss1, const void *ss2, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);

int				ft_atoi(const char *str);
char			*ft_itoa(int n);

char			*ft_strreplace(char *haystack, char *needle, char *new_needle);
char			*ft_strdup(const char *s1);
char			*ft_strndup(const char *s1, size_t n);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strnjoin(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);

char			*ft_strtoupper(const char *src);
char			*ft_strtolower(const char *src);

char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *dest, const char *src, size_t nb);
size_t			ft_strlcat(char *dest, const char *src, size_t size);

char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle, size_t n);
char			**ft_strsplit(char const *s, char c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);

int				ft_putchar_fd(char c, int fd);
int				ft_putnchar_fd(int fd, int n, char c);
int				ft_putstr_fd(char const *s, int fd);
int				ft_putnstr_fd(int n, char const *s, int fd);
int				ft_putendl_fd(char const *s, int fd);
int				ft_putnbr_fd(int n, int fd);
int				ft_putnbr_base_fd(int fd, int nbr, char *base);

int				ft_putnbr_base(int nbr, char *base);
int				ft_putnchar(int n, char c);
int				ft_putchar(char c);
int				ft_putstr(char const *s);
int				ft_putnstr(int n, char const *s);
int				ft_putendl(char const *s);
int				ft_putnbr(int n);

int				ft_abs(int n);
int				ft_sqrt(int nb);

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstadd(t_list **alst, t_list *new_node);
void			ft_lstrev(t_list **head);
void			ft_lstsort(t_list **head, int (*cmp)(void*, void*));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int				ft_int_min(int *arr, unsigned int len);
int				ft_int_max(int *arr, unsigned int len);
void			ft_int_sort(int *arr, unsigned int len);
float			ft_int_average(int *arr, unsigned int len);

int				ft_gnl(const int fd, char **line);

#endif