#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

//#define BUFFER_SIZE 32

typedef struct s_list {
	char *str;
	struct s_list *next;
} t_list;

char	*ft_strndup(char *str, int max);
char	*ft_strdup(char *str);
t_list	*ft_new(char *s, t_list *lst);
char	*ft_join(char *s1, char *s2);
int		ft_ft(int fd, char **line);
int		get_next_line(int fd, char **line);
