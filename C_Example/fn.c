#include<stdio.h>

void print(char *p) {
    for (int i = 0; i < 4; i++)
        printf("%c\n", *p++);
}
int main() {
    char str[] = "A#BC";
    char *p = str;
    print(p);

    return 0;
}