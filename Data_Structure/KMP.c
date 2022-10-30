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
    while (insert_ss[i]!= '\0') {
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
    int i = pos, j = 0;
    while (i < S->length && j < T->length) {
        if (S->ch[i] == T->ch[j]) {
            ++i;
            ++j;
        }
        else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == T->length)
        return i - T->length + 1;
    else
        return -1;
}
void GetNext(const SString *T, int next[])
{
    int i = 0, j = -1;
    next[0] = -1;
    while (i < T->length) {
        if (j == -1|| T->ch[i] == T->ch[j]) {
            ++i;
            ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
}
int KMP_Index(SString *S, SString *T, int next[], int pos)
{
    int i = pos;
    int j = 0;
    while (i < S->length && j < T->length) {
        if (j == -1|| S->ch[i] == T->ch[j]) {
            ++i;
            ++j;
        }
        else
            j = next[j];
    }
    if (j == T->length)
        return i - T->length + 1;
    else
        return -1;
}
void main()
{
    int next[100];
    SString *S = CreateString(20);
    SString *T = CreateString(5);
    InsertString(S, "11223344555");
    InsertString(T, "34450");
    int bf_t = BF_Index(S, T, 0);
    GetNext(T, next);
    int kmp_t = KMP_Index(S, T, next, 0);
    printf("%d\n",bf_t);
    printf("%d\n",kmp_t);
}