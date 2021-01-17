/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 14:01:35 by sserbin           #+#    #+#             */
/*   Updated: 2021/01/17 14:01:36 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*ft_new(char *s, t_list *lst, int fd)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	tmp->str = s;
	tmp->fd = fd;
	tmp->next = lst;
	return (tmp);
}

void	ft_free_that_list(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->str);
		free(*lst);
		*lst = tmp;
	}
}

size_t	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_get_last_string(t_list **lst, int fd)
{
	t_list	*tmp;

	tmp = *lst;
	if (!tmp)
		return ("");
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp->str);
		tmp = tmp->next;
	}
	return ("");
}

char	*ft_join(char *s1, char *s2, int max)
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
