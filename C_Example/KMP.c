#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct 
{
    char *ch;
    int length;
}SString;
SString *CreateString(int length)
{
    SString *ss = (SString*)malloc(sizeof(SString));
    ss->ch = (char*)malloc(sizeof(char)*length);
    return ss;
}
void InsertString(SString *ss, char insert_ss[])
{
    int i = 0;
    while (insert_ss[i]!= '\0')
    {
        ss->ch[i] = insert_ss[i];
        i++;
        ss->length++;
    }
}
void OutputString(SString *ss)
{
    for(int i = 0; i < ss->length; i++)
        printf("%c",ss->ch[i]);
    printf("\n");
}
int BF_Index(SString *S, SString *T, int pos)
{
    
}
void main()
{
    SString *S = CreateString(20);
    SString *T = CreateString(5);
    InsertString(S, "abc123");
    OutputString(S);
}