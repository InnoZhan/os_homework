#include <stdio.h>

void swap(int *i1, int *i2) {
    int temp;
    temp = *i1;
    *i1 = *i2;
    *i2 = temp;
}

int main() {
    int a, b;
    printf("Please input two numbers to swap\n");
    scanf("%d %d", &a, &b);
    swap(&a, &b);
    printf("%d %d", a, b);
    return 0;
}