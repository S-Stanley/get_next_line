#include "get_next_line.h"

char	*ft_join(char *s1, char *s2)
{
	int		i;
	int		x;
	char	*str;

	i = -1;
	x = -1;
	str = malloc(sizeof(char) * ( (int)strlen(s1) + (int)strlen(s2) + 1));
	while(s1[++i])
		str[i] = s1[i];
	while(s2[++x])
		str[i++] = s2[x];
	str[i] = 0;
	return (str);
}

int		ft_ft(int fd, char **line, t_list **lst, char *tmp)
{
	int			size;
	int			i;
	char		*str;
	char		*s;
	char		*rem;

	s = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	size = read(fd, s, BUFFER_SIZE);
	s[size] = 0;
	str = ft_join(tmp, s);
	free(s);
	if (size == 0 && (int)strlen(str) == 0)
	{
		free(str);
		return (0);
	}
	i = -1;
	while (str[++i])
	{
		if (str[i] == '\n')
		{
			rem = ft_strdup(&str[i + 1]);
			*lst = ft_new(rem, *lst);
			*line = ft_strndup(str, i);
			free(str);
			return (1);
		}
	}
	rem = ft_strdup(str);
	free(str);
	*lst = ft_new(rem, *lst);
	return (2);
}

int		get_next_line(int fd, char **line)
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

