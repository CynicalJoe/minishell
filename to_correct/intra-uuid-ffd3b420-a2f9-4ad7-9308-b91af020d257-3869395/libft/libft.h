/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:11:45 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/16 12:15:01 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <errno.h>
# include <stdarg.h>

# define ULL_MAX 9223372036854775807
# define ULL_MIN -9223372036854775808
# define TRUE 1
# define FALSE 0

typedef unsigned long long	t_ull;
typedef long long			t_ll;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

void		*ft_memset(void *b, int c, size_t len);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
size_t		ft_strlen(const char *s);
int			ft_atoi(const char *str);
t_ll		ft_atol(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strcpy(const char *src, char *dest);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			is_charset(char c, char *charset);
void		is_error(char *str_1, char *str_2, char *err_msg, int exit_status);
int			ft_toupper(int c);
int			ft_tolower(int c);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);
char		*ft_strndup(const char *s1, size_t n);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
char		**ft_split_charset(char const *s, char *charset);
int			ft_strsetlen(char **strs);
char		*ft_strrnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strchrset(const char *s, char *charset);
char		*ft_strrchrset(const char *s, char *charset);
void		bubble_sort_strset(char **strset, int len);
void		swap_char(char *a, char *b);
char		*strchrset_skip_bs(const char *s, char *charset);
char		*ft_str_toupper(char *s);

//  extra
size_t		ft_strarray_length(char **str_array);
char		*ft_append_char_to_str(char *s, char c);
char		**ft_addstr_to_strarray(char **array, char *str, bool free_array);
void		*ft_destroy_strarray(char ***str_array);
char		*ft_append_str(char *s1, char *s2, bool frees1, bool frees2);
size_t		ft_ull_ibase_len(unsigned long long number, int ibase);
char		*ft_lltoa_ibase(long long number, int base, bool uppercase);
char		*ft_ulltoa_ibase(unsigned long long number, int ibase,
				bool uppercase);
char		*fill_res(unsigned long long number, int ibase, char *res, int len);
char		**ft_copy_strarray(char **str_array);
char		**ft_sort_strarray(char **strarray);

/*
** To handle List
*/

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *newnode);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *newnode);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*));

#endif
