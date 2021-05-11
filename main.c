#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int main() {
//	int fd = open("/Users/atory/CLionProjects/GNL/test.txt", O_RDWR);
	int fd = open("/Users/atory/21tests/Tgnl/tester/test/normal.txt", O_RDWR);
	char *line;

	while (get_next_line(fd, &line) == 1)
	{
		printf("%s\n", line);
		free(line);
	}

//	get_next_line(fd, &line);
	printf("%s", line);
	free(line);
//	printf("%lu aaaaaaa\n", sizeof(char **));
//	while(1)
//	{
//
//	}
    return 0;
}
