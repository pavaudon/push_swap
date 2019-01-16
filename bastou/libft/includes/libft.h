/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/09 20:40:59 by bchanot           #+#    #+#             */
/*   Updated: 2016/10/20 11:18:45 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 32
# define _ERROR_ 0x00
# define _SUCCESS_ 0x01

# include <string.h>
# include <wchar.h>

typedef enum		e_bool
{
	false,
	true
}					t_bool;

int					ft_printf(const char *format, ...);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isnum(const char *s);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isalnum(int c);
int					ft_atoi(const char *str);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
char				*ft_itoa(long long int n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(long int nb);
void				ft_putnbrlong(long long int nb);
void				ft_putnbr_fd(long int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnjoin(char const *s1, char const *s2, size_t n);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				ft_puttab(char **tab);
size_t				ft_cptchar(char *str, char c);
void				ft_exit(const char *str);
void				ft_exit_err(const char *str);
int					ft_sqrt(int nb);
char				*ft_htoa(long long unsigned int nb);
char				*ft_utoa(long long unsigned int nb);
int					ft_nbrlen(long long int nb);
int					ft_nbrlonglen(long long int nb);
int					ft_nbrulen(unsigned int nb);
int					ft_nbrlgulen(long long unsigned int nb);
char				*ft_widechar(wchar_t c);
char				*ft_widestr(wchar_t *src);
char				*ft_itob(int nb);
long long int		ft_itoo(long long unsigned int nb);
int					ft_get_next_line(int const fd, char **line);
int					ft_getchar_fd(int fd);
int					ft_getchar(void);
char				*ft_getstr_fd(int fd, char x);
char				*ft_getstr(char x);
char				*ft_strcut(char *str, char c);
char				*ft_charjoin(char const *s1, char const c);
int					ft_isupper(char c);
int					ft_check_last(char *src, int c, char *str);
int					ft_strisdigit(char *str);
void				ft_memdel2(void ***ap);
void				ft_swap(int *a, int *b);

#endif
