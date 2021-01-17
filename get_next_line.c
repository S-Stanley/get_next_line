/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 12:34:44 by sserbin           #+#    #+#             */
/*   Updated: 2021/01/17 13:45:11 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_ft(char **line, t_list **lst, char *str, int fd)
{
	int			i;
	char		*rem;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\n')
		{
			rem = ft_join("", &str[i + 1], -1);
			*lst = ft_new(rem, *lst, fd);
			*line = ft_join("", str, i);
			return (1);
		}
	}
	rem = ft_join("", str, -1);
	*lst = ft_new(rem, *lst, fd);
	return (2);
}

t_render	ft_read_file(int fd)
{
	char		*s;
	int			size;
	t_render	tmp;

	s = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!s)
	{
		tmp.count = -1;
		tmp.render = NULL;
		return (tmp);
	}
	size = read(fd, s, BUFFER_SIZE);
	if (size != -1)
		s[size] = 0;
	tmp.count = size;
	tmp.render = s;
	return (tmp);
}

int			ft_clean(char **line, t_list **lst, char **str)
{
	*line = ft_join("", *str, -1);
	ft_free_that_list(lst);
	free(*str);
	return (0);
}

int			ft_loop(int fd, t_list **lst, char **line)
{
	char		*rem;
	char		*str;
	t_render	data;
	int			res;

	rem = ft_get_last_string(lst, fd);
	data = ft_read_file(fd);
	if (data.count == -1)
		return (-1);
	str = ft_join(rem, data.render, -1);
	if ((int)ft_strlen(str) == 0)
	{
		free(data.render);
		return (ft_clean(line, lst, &str));
	}
	free(data.render);
	res = ft_ft(line, lst, str, fd);
	if (res == 2 && data.count == 0)
		return (ft_clean(line, lst, &str));
	free(str);
	return (res);
}

int			get_next_line(int fd, char **line)
{
	int				res;
	static t_list	*lst;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || !fd)
		return (-1);
	res = 2;
	while (res == 2)
	{
		res = ft_loop(fd, &lst, line);
	}
	return (res);
}
