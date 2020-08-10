# GNL
## Project objective
  Write a function that will allow to read a line ending with a newline character from a file descriptor.
## Skills to acquire and use
•	Fundamentals of C  
•	Rigor  
•	Algorithm elaboration  
•	Imperative programming  
•	Learn a new concept in C programming - static variables  
## How to run it? (works on Linux and MacOS)
•	git clone https://github.com/DaniilMD/GNL.git "Folder name"  
•	cd "Folder name"  
•	cd libft  
•	make  
•	cd ..  
•	gcc main.c get_next_line.c -I . -L libft -lft -o gnl_test  
•	./gnl_test "Text file name"  
  
For example, you can use an already created main that looks like this (it uses 2 libft functions to print the result):  
```
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
```
As the first argument you can use an example text with an article about space.  
  
![Screenshot from 2020-08-10 18-33-50](https://user-images.githubusercontent.com/48802453/89800973-298d5080-db38-11ea-8025-67fa3591b071.png)  
  
Result is going to be something like this:  
  
![Screenshot from 2020-08-10 18-30-35](https://user-images.githubusercontent.com/48802453/89801037-4164d480-db38-11ea-9b48-f975be61c89d.png)  
  
## What does it do?
get_next_line() is a function that recieves a file descriptor and an address of a pointer to a character. This address will be used to save the line read from the file descriptor.  
Calling function get_next_line() in a loop allows to read the text available on a file descriptor one line at a time until the end of the text, no matter the size of either the text or one of its lines.  
## How it works
1) get_next_line() uses a static array of char* - static char	*extra_line[256]. Each char* contains the text of a specific file descriptor (256 max can be handled simultaneously).  
2) GNL reads portions of text (with a size of macro BUFF_SIZE) in a cycle until at least 1 completed line appears. Completed line is a succession of characters that end with ’\n’ or with End Of File (EOF). This line is returned.  
3) This process can be repeated successfully without losing a single character because all data is saved in a static variable which has a lifetime of a whole program run.  
## Project evaluation result  
### Score 100/100  
Mandatory part  
125/100  
  
Bonus part  
25/25  
  
Bonuses were:  
• To succeed get_next_line with a single static variable.  
• To be able to manage multiple file descriptors with get_next_line() without losing the reading thread on each of the descriptors.  
