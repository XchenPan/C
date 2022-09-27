#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <sys/time.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

char true_random()
{
    char random_num, fd, nread;
    fd = open("/dev/random", O_RDONLY);
    if(fd < -1)
        return -1;
    nread = read(fd, &random_num, sizeof(random_num));
    if(nread < 0)
        return -1;
    close(fd);
    if(random_num < 0)
        random_num = -random_num;
    if(random_num <= 1000)
        return random_num;
    else
        return true_random();
}
void main()
{
    int n;
    n = true_random();

    printf("n = %d\n",n);
}