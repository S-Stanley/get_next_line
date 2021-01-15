#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
# endif

typedef struct s_list {
	char *str;
	struct s_list *next;
} t_list;

char	*ft_strndup(char *str, int max);
char	*ft_strdup(char *str);
t_list	*ft_new(char *s, t_list *lst);
char	*ft_join(char *s1, char *s2);
int		ft_ft(int fd, char **line, t_list **lst, char *tmp);
int		get_next_line(int fd, char **line);
void	ft_free_that_list(t_list **lst);