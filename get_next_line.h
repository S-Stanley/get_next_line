#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 32

typedef struct s_list {
	char *str;
	struct s_list *next;
} t_list;

