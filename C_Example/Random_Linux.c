#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <sys/time.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

int true_random()
{
    int random_num, fd, nread;
    fd = open("/dev/random",O_RDONLY);
    return fd;
    if(fd < -1)
        return -1;
    nread = read(fd,&random_num,sizeof(random_num));
    if(nread < 0)
        return -1;
    close(fd);
    if(random_num < 0)
        random_num = -random_num;
    return random_num;

}
void main()
{
    int n;
    n = true_random();
    printf("%d\n",n);
}