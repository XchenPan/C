#include<stdio.h>
#include<sys/time.h>
#include<time.h>

void main()
{
    struct timeval start,end;
    gettimeofday(&start, NULL );
    //…calculating…
    gettimeofday(&end, NULL );
    long timeuse =1000000 * ( end.tv_sec - start.tv_sec ) + end.tv_usec - start.tv_usec;
    printf("time=%f\n",timeuse /1000000.0);

    // time_t start,end;
    // start = time(NULL);//or time(&start);
    // //…calculating…
    // end = time(NULL);
    // printf("time=%f\n",difftime(end,start));

    // clock_t start,end;
    // start = clock();
    // //…calculating…
    // end = clock();
    // printf("time=%f\n",(double)(end-start)/CLK_TCK);
}