#include<stdio.h>
long func(long x, long y)
{
    long m = x - y;
    long n = x + y;
    if(x <= y)
        m=n;
    return m;
}
int main()
{
	long a,b;
	scanf("%ld%ld",&a,&b);
	printf("%ld",func(a,b));
	return 0;
}