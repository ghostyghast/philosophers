/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:15:32 by amaligno          #+#    #+#             */
/*   Updated: 2023/08/11 17:21:41 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_int
{
	int				num;
	int				index;
	struct s_int	*next;
	struct s_int	*prev;
}		t_int;

//libft
long	ft_atoi(char *str);
void	ft_putendl_fd(char *s, int fd);

int		ft_strcmp(char *s1, char *s2);
int		ft_lstsize(t_int *lst);
t_int	*ft_lstnew(int num);
t_int	*ft_lstlast(t_int *lst);
void	ft_lstclear(t_int **lst);
void	ft_lstdelone(t_int *lst);
void	ft_lstadd_front(t_int **lst, t_int *new);
void	ft_lstadd_back(t_int **lst, t_int *new);

//ft_printf
int		ft_printf(const char *str, ...);
void	writer(const char *str, int *i);
void	ft_putchar(int c, int *i);
void	ft_putnbr(int nb, int *len);
void	ft_putunsigned(unsigned int nb, int *len);
void	ft_puthexa(unsigned int n, int *len);

//get_next_line
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*to_send(char *str);

void	*ft_memcpy(void *dst, void *src, size_t n);

size_t	length(char *str);
int		strcheck(char *s);

#endif