#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# include "libft/libft.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

int		line_runner(char **line, char **extra_line, int reader);
int		get_next_line(const int fd, char **line);

#endif
