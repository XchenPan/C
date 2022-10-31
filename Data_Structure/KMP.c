#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>

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
    SString *S = CreateString(100);
    SString *T = CreateString(20);
    InsertString(S, "0000000000000000000000000000000000000000000000000000000000001122334004555");
    InsertString(T, "0045");
    int next[100];
    GetNext(T, next);
    int s = -1;

    time_t tBegin, tEnd;
    time(&tBegin);
    for (int i = 0; i < 10000000; i++) {
        s = KMP_Index(S, T, next, 0);
        // s = BF_Index(S, T, 0);
    }
    time(&tEnd);
    printf("本次搜索耗时：%d\n", tEnd - tBegin);

    struct timeval gtod_start, gtod_end;
    gettimeofday(&gtod_start, NULL);
    for (int i = 0; i < 10000000; i++) {
        s = KMP_Index(S, T, next, 0);
        // s = BF_Index(S, T, 0);
    }
    gettimeofday(&gtod_end, NULL);
    long timeuse = 1000000 * (gtod_end.tv_sec - gtod_start.tv_sec) + gtod_end.tv_usec - gtod_start.tv_usec;
    printf("本次搜索耗时：%f\n", timeuse / 1000000.0);

    clock_t clk_start, clk_end;
    clk_start = clock();
    for (int i = 0; i < 10000000; i++) {
        s = KMP_Index(S, T, next, 0);
        // s = BF_Index(S, T, 0);
    }
    clk_end = clock();
    printf("本次搜索耗时：%f\n",(double)(clk_end-clk_start) / CLOCKS_PER_SEC);

    printf("主串中找到模式串位置为（从1开始）：%d\n", s);
}