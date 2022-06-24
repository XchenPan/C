#include<stdio.h>
int func(int x,int y)
{
    int m,n;
    if(x <= 9){
        m = x + y;
       n = x;
       n = n - y;
       if(x >= y)
            m=n;
    }
    else{
        m = 13;
        y = x * y;
        if(x <= 19)
            m=y;
    }
    return m;
}
int main()
{
    int x,y;

    scanf("%d%d",&x,&y);

    printf("%d\n",func(x,y));
    
    return 0;
}