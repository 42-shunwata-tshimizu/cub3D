#include "../srcs/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char *get_next_line(int fd);

int main(void)
{
    int fd1 = open("test1.txt", O_RDONLY);
    int fd2 = open("test2.txt", O_RDONLY);

    if (fd1 < 0 || fd2 < 0)
    {
        perror("open");
        return 1;
    }

    char *line1;
    char *line2;

    line1 = get_next_line(fd1);
    printf("fd1: %s", line1);
    free(line1);

    line2 = get_next_line(fd2);
    printf("fd2: %s", line2);
    free(line2);

    line1 = get_next_line(fd1);
    printf("fd1: %s", line1);
    free(line1);

    line2 = get_next_line(fd2);
    printf("fd2: %s", line2);
    free(line2);

    close(fd1);
    close(fd2);
    return 0;
}
