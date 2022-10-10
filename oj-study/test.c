#include<stdio.h>
int main()
{
    int a = 0, b = 0;
    int m, n;
    for(int i =0; i < 5; i++)
    {
        m = a++;
        n = ++b;
    }
    printf("%d %d\n", m, n);
    printf("this is a c-test program !\n");
    return 0;
}