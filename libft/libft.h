#ifndef LIBFT_H
# define LIBFT_H

# define BUFFER_SIZE 512

# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <math.h>
# include <time.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

/*
 * dynamic matrix that can automatically expand when necessary
 * methods:
 *   ft_darrnew
 *   ft_darrpushback
 *   ft_darrclear
 *   ft_darrerase
 */
typedef struct s_darr
{
	char		**ptr;
	size_t		len;
	size_t		cap;
}				t_darr;

void			ft_exit(const char *msg, int code);
int				ft_abs(int nb);
size_t			ft_strlen(const char *s);
int				ft_isdigitstr(char *str);
int				ft_isspace(char c);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t cnt);
void			*ft_memmove(void *str1, const void *str2, size_t n);
void			*ft_memchr(const void *str, int c, size_t n);
int				ft_memcmp(const void *str1, const void *str2, size_t n);
size_t			ft_strlcpy(char *dest, const char *src, size_t dsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *str, int c);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_atoi(const char *str);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin3(const char *s1, const char *s2, const char *s3);
char			*ft_strjoinsafe(char **s1, char **s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char *str, int d);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
int				ft_matrixlen(char **matrix);
void			ft_freematrix(char **matrix);
t_darr			*ft_darrnew(size_t cap);
void			ft_darrpushback(t_darr *darr, char *item);
void			ft_darrclear(t_darr *darr);
void			ft_darrerase(t_darr *darr, char *item);
int				get_next_line(int fd, char **line);

#endif
