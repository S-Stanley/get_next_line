/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 14:01:26 by sserbin           #+#    #+#             */
/*   Updated: 2021/01/17 14:01:28 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct	s_list
{
	char			*str;
	int				fd;
	struct s_list	*next;
}				t_list;

typedef struct	s_render
{
	char			*render;
	int				count;
}				t_render;

char			*ft_strndup(char *str, int max);
t_list			*ft_new(char *s, t_list *lst, int fd);
char			*ft_join(char *s1, char *s2, int max);
int				ft_ft(char **line, t_list **lst, char *str, int fd);
int				get_next_line(int fd, char **line);
void			ft_free_that_list(t_list **lst);
t_render		ft_read_file(int fd);
size_t			ft_strlen(char *str);
int				ft_free_and_return(char **str, t_list **lst, int mode, char *s, int fd);
char			*ft_get_last_string(t_list **lst, int fd);
int				ft_strcmp(char *s1, char *s2);
int				ft_loop(int fd, t_list **lst, char **line);

#endif
