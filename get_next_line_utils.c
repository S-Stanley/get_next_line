#include "get_next_line.h"

char	*ft_strndup(char *str, int max)
{
	int	i;
	char	*s;
	
	s = malloc(sizeof(char) * ((int)strlen(str) + 1));
	i = -1;
	while (str[++i] && i <  max)
		s[i] = str[i];
	s[i] = 0;
	return (s);

}

char	*ft_strdup(char *str)
{
	char	*s;
	int	i;

	i = -1;
	s = malloc(sizeof(char) * ((int)strlen(str) + 1));
	while (str[++i])
		s[i] = str[i];
	s[i] = 0;
	return (s);
}

t_list	*ft_new(char *s, t_list *lst)
{
	t_list *tmp;

	tmp = malloc(sizeof(t_list));
	tmp->str = s;
	tmp->next = lst;
	return (tmp);

}

void	ft_free_that_list(t_list **lst)
{
	t_list *tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->str);
		free(*lst);
		*lst = tmp;
	}
}