/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 17:58:47 by cbagdon           #+#    #+#             */
/*   Updated: 2019/05/15 22:51:41 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
**	INCLUDES SECTION
*/

# include "ft_printf.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

/*
**	MACROS
*/

# define ABS(n)				((n >= 0) ? n : -n)
# define IS_DIGIT(c)		((c >= '0' && c <= '9') ? 1 : 0)
# define IS_SIGN(c)			((c == '+' || c == '-') ? 1 : 0)
# define IS_SPACE(c)		((c == ' ' || c == '\n' || c == '\t') ? 1 : 0)
# define MEM_CHK(c)			if (!c) return (NULL)

/*
**	COLORS
*/

# define C_RED "\x1b[0;31m"
# define C_GREEN "\x1b[0;32m"
# define C_YELLOW "\x1b[0;33m"
# define C_BLUE "\x1b[0;34m"
# define C_MAGENTA "\x1b[0;35m"
# define C_CYAN "\x1b[0;36m"
# define C_WHITE  "\x1b[0m"

/*
**	FUNCTION PROTOTYPES
*/

size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
		size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/*
*********************
**	FUNCTIONS PT. 2
*********************
*/

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
int					ft_getwordcount(char const *str, char c);
char				**ft_strsplit(char const *s, char c);
int					ft_intlen(int num);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					get_next_line(const int fd, char **line);

/*
**********************
**	STRUCTURES
**********************
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
**********************
**	BONUS
**********************
*/

t_list				*ft_lstnew(void const *content, size_t contentsize);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstpush(t_list **head, t_list *new);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
**********************
**	PERSONAL
**********************
*/

char				*ft_strccpy(char *dst, const char *src, const char c);
char				*ft_strndup(const char *src, int n);
char				*ft_stroverlap(char *dst, const char *src);
void				ft_strmove(char *dst, const char *src);
void				ft_strrev(char *str);
int					ft_starts_with(char *to_start, char *str);
char				*ft_strjoinch(char *s1, char c);
char				*ft_strjoinchf(char *str, char c);
char				*ft_strjoinf(char *s1, char *s2);
char				*ft_pathjoin(char *s1, char *s2);
void				ft_freestrarray(char **str);
char				*ft_itoa_base(int number, int base);
char				*ft_strnjoin(char const *s1, char const *s2, int n);

#endif
