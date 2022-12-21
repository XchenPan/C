#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
#include<string.h>
#define MAX 20

typedef struct 
{
    int *data;
    int length;
    int capacity;
}SepList;

SepList *SL_create(int capacitylength)
{
    SepList *slist = (SepList*)malloc(sizeof(SepList));
    slist->data = (int*)malloc(sizeof(int)*capacitylength);
    slist->capacity = capacitylength;
    slist->length = 0;
    return slist;
}
void SL_Free(SepList *slist)
{
    free(slist->data);
    free(slist);
}
void SL_Extence(SepList *slist)
{
    assert(slist->data != NULL);
    slist->data = (int*)realloc(slist->data , slist->capacity * 2 * sizeof(int));
    assert(slist->data != NULL);
    slist->capacity *= 2;
}
void SL_Save(SepList *slist, int a[], int n)
{
    for (int i = 0; i < n; i++) {
        slist->data[i] = *a++;
        slist->length++;
    }
}
void SL_output(SepList *slist)
{
    if(slist->length == 0){
        printf("The slist is empty.\n");
        return;
    }
	int i=0;
	while(i < slist->length)
	{
		printf("%d ",slist->data[i]);
		++i;
	}
    printf("\n");
}
void InsertSort(SepList *slist)
{
    if(slist->length == 0) return;
    for(int i = 1; i < slist->length; i++){
        int t = slist->data[i];
        int j;
        for(j = i-1; j >= 0; j--){
            if(slist->data[j] > t)
               slist->data[j + 1] = slist->data[j];
            else break;
        }
        slist->data[j + 1] = t;
    }
}
void ShellSort(SepList *slist) 
{
    int gap = slist->length;
	while (gap) {
		gap = gap / 2;
		for (int i = 0; i <= (slist->length - 1) - gap; i++) {
			int end = i;
			int tmp = slist->data[end + gap];
			while (end >= 0) {
				if (slist->data[end] > tmp) {
					slist->data[end + gap] = slist->data[end];
					end -= gap;
				}
				else break;
			}
			slist->data[end + gap] = tmp;
		}
		if (gap == 1) break;
	}
}
int partition(SepList *slist, int left, int right)
{
    int key = slist->data[left];
	int begin = left;
	int end = right;
	while(begin != end){
		while(begin < end && slist->data[end] >= key)
			end--;
		if(end > begin)
			slist->data[begin] = slist->data[end];
		while(begin < end && slist->data[begin] <= key)
			begin++;
		if(begin < end)
			slist->data[end] = slist->data[begin];
	}
	slist->data[begin] = key;

    return begin;
}
void QuickSort(SepList *slist, int left, int right)
{
	if(left >= right) return;
    int p = partition(slist, left, right);
	QuickSort(slist, left, p);
	QuickSort(slist, p + 1, right);
}
void main()
{
    SepList *slist1 = SL_create(MAX);
    SepList *slist2 = SL_create(MAX);
    SepList *slist3 = SL_create(MAX);
    int a[] = {36, 42, 65, 98, 76, 14, 57, 36};
    int n = sizeof(a) / sizeof(int);
    SL_Save(slist1, a, n);
    SL_Save(slist2, a, n);
    SL_Save(slist3, a, n);
    printf("未排序的数据：");
    SL_output(slist1);
    InsertSort(slist1);
    printf("通过插入排序后的数据：");
    SL_output(slist1);
    ShellSort(slist2);
    printf("通过希尔排序后的数据：");
    SL_output(slist2);
    QuickSort(slist3, 0, 7);
    printf("通过快速排序后的数据：");
    SL_output(slist3);
    SL_Free(slist1);
    SL_Free(slist2);
    SL_Free(slist3);
}