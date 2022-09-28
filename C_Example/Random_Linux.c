#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <sys/time.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include<time.h>

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
    return random_num;
}
void main()
{
    int m, n;
    srand((unsigned int)time(NULL));
    n = true_random();
    for(int i = 0; i < 5; i++){
        n = true_random();
        printf("n = %d %c\n",n,(char)n);
    }
    printf("%d\n", m = rand()%101+100);
    //printf("n = %d %c\n",n,(char)n);
}