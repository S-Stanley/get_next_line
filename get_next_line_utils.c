/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 12:35:01 by sserbin           #+#    #+#             */
/*   Updated: 2021/01/16 12:35:03 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_new(char *s, t_list *lst)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	tmp->str = s;
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

char	*ft_get_last_string(t_list **lst)
{
	if (!(*lst))
		return ("");
	else
		return ((*lst)->str);
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
