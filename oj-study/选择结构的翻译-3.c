#include<stdio.h>
int func(int x,int y,int z)
{
    int m,n;
    if(x < y){
        m = z;
        m = m - y;
        n = y;
        n = n-z;
        if(y >= z)
            m=n;
    }
    else{
        m = z;
        m = m - x;
        n = x;
        n = n - z;
        if(x >= z)
            m=n; 
    }
    return m;
}
int main()
{

    int a,b,c;

    scanf("%d%d%d",&a,&b,&c);

    printf("%d\n",func(a,b,c));

    return 0;

}