
#include "get_next_line.h"

int main()
{
	int fd;
	char *s;
	fd = open("test.txt",O_RDONLY);
	s = get_next_line(fd);
	printf("%s",s);
}