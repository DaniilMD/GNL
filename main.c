#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int fd;
	char *line;

	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		ft_putstr(line);
		ft_putchar('\n');
	}
	free(line);
}