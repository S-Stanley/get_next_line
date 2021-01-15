#include "get_next_line.h"

int main(void)
{
	char *line;
	int fd = open("data", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		printf("%s\n", line);
	return (0);
}

