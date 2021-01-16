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

char		*ft_join(char *s1, char *s2, int max)
{
	int		i;
	int		x;
	char	*str;
	int		maxi;

	i = -1;
	x = -1;
	if (max == -1)
		maxi = ft_strlen(s1) + ft_strlen(s2) + 2;
	else
		maxi = max;
	str = malloc(sizeof(char) * ((int)ft_strlen(s1) + (int)ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++x] && i < maxi)
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
		rem = ft_join("", *str, -1);
		*lst = ft_new(rem, *lst);
		free(*str);
	}
	else
	{
		(void)str;
		rem = ft_join("", s, -1);
		*lst = ft_new(rem, *lst);
	}
	return (2);
}

int			ft_ft(char **line, t_list **lst, char *str)
{
	int			i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\n')
		{
			ft_free_and_return(&str, lst, 0, &str[i + 1]);
			*line = ft_join("", str, i);
			free(str);
			return (1);
		}
	}
	return (ft_free_and_return(&str, lst, 1, ""));
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

int			get_next_line(int fd, char **line)
{
	int				res;
	static t_list	*lst;
	char			*str;
	t_render		data;
	char			*rem;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || !fd)
		return (-1);
	res = 2;
	while (res == 2)
	{
		rem = ft_get_last_string(&lst);
		data = ft_read_file(fd);
		if (data.count == -1)
			return (-1);
		str = ft_join(rem, data.render, -1);
		if ((int)ft_strlen(str) == 0)
		{
			*line = ft_join("", str, -1);
			ft_free_that_list(&lst);
			free(data.render);
			return (0);
		}
		free(data.render);
		res = ft_ft(line, &lst, str);
		if (res == 2 && data.count == 0)
		{
			*line = ft_join("", str, -1);
			ft_free_that_list(&lst);
			return (0);
		}
	}
	return (res);
}
