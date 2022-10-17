#include"StackH.h"

int caculate(int v1, int v2, char opt) {
    //求一个双目运算的值
    T result;
    if (opt == '+')
        result = v1 + v2;
    if (opt == '-')
        result = v1 - v2;
    if (opt == '*')
        result = v1 * v2;
    if (opt == '/')
        result = v1 / v2;
    
    return result;
}
int evaluate(char* expression) {
    //求后缀表达式expression的值，expression以'\0'结尾
    struct SepStack *value  = SS_Create(100);
    char ch;
    char m, n, result;
    int i = 0;
    while (expression[i] != '#')
    {
        if (expression[i] == '+'||expression[i] == '-'||expression[i] == '*'||expression[i] == '/') {
            ch = expression[i];
            m = Pop(value) ;
            n = Pop(value);
            result = caculate(n, m, ch);
            Push(value, result);
            i++;
        }
        else {
            Push(value, expression[i] - '0');       //将char转化为int
            i++;
        }
    }
    return Pop(value);
}
void main()
{
    // struct SepStack *sstack = SS_Create(MaxSize);
    // Push(sstack, 56);
    // Push(sstack, 77);
    // Push(sstack, 15);
    // Push(sstack, 12);
    // Push(sstack, 8);
    // Output(sstack);
    // Push(sstack, 444);
    // // printf("取出当前栈顶元素为：%d\n",Pop(sstack));
    // // printf("读到当前栈顶元素为：%d\n",Peek(sstack));

    // Output(sstack);

    char expr1[] = "34-5+#";
    char expr2[] = "645/26*+-#";
    char expr3[] = "322*23*+-#";
    printf("%d\n", evaluate(expr2)); 
}