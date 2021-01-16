/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 12:34:44 by sserbin           #+#    #+#             */
/*   Updated: 2021/01/16 12:34:46 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_join(char *s1, char *s2)
{
	int		i;
	int		x;
	char	*str;

	i = -1;
	x = -1;
	str = malloc(sizeof(char) * ((int)strlen(s1) + (int)strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++x])
		str[i++] = s2[x];
	str[i] = 0;
	return (str);
}

int			ft_free_and_return(char **str, t_list **lst, int mode, char *s)
{
	char	*rem;

	if (mode)
	{
		(void)s;
		rem = ft_strndup(*str, -1);
		*lst = ft_new(rem, *lst);
		free(*str);
	}
	else
	{
		(void)str;
		rem = ft_strndup(s, -1);
		*lst = ft_new(rem, *lst);
	}
	return (2);
}

t_render	ft_read_file(int fd)
{
	char		*s;
	int			size;
	t_render	tmp;

	s = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!s)
		return (tmp);
	size = read(fd, s, BUFFER_SIZE);
	s[size] = 0;
	tmp.count = size;
	tmp.render = s;
	return (tmp);
}

int			ft_ft(int fd, char **line, t_list **lst, char *tmp)
{
	int			i;
	char		*str;
	char		*rem;
	t_render	data;

	data = ft_read_file(fd);
	str = ft_join(tmp, data.render);
	free(data.render);
	if (data.count == 0 && (int)strlen(str) == 0)
	{
		free(str);
		return (0);
	}
	i = -1;
	while (str[++i])
	{
		if (str[i] == '\n')
		{
			ft_free_and_return(&str, lst, 0, &str[i + 1]);
			*line = ft_strndup(str, i);
			free(str);
			return (1);
		}
	}
	return (ft_free_and_return(&str, lst, 1, ""));
}

int			get_next_line(int fd, char **line)
{
	int				res;
	static t_list	*lst;
	t_list			*tmp;
	char			*str;

	if (!fd)
		return (-1);
	res = 2;
	while (res == 2)
	{
		if (!lst)
			str = "";
		else
			str = lst->str;
		res = ft_ft(fd, line, &lst, str);
	}
	if (res == 0)
		ft_free_that_list(&lst);
	return (res);
}
