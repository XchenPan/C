#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int SL_Random_2(int max, int min)
{
    int n;
    n = rand() % (max - min + 1) + min;
    return n;
}
int main()
{
    int a[20];
    srand((int)time(NULL));
    for(int i = 0; i < 20; i++)
        a[i] = SL_Random_2(100, 0);
    for(int j = 0; j < 20; j++)
        printf("%d ",a[j]);
    return 0;
}