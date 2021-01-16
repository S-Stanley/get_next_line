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

char	*ft_strndup(char *str, int max)
{
	int		i;
	char	*s;
	int		maxi;

	if (max == -1)
		maxi = ft_strlen(str) + 2;
	else
		maxi = max;
	s = malloc(sizeof(char) * ((int)ft_strlen(str) + 1));
	if (!s)
		return (NULL);
	i = -1;
	while (str[++i] && i < maxi)
		s[i] = str[i];
	s[i] = 0;
	return (s);
}

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

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] || s2[i])
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	return (0);
}