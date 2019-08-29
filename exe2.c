#include <stdio.h>
#include <string.h>

int main() {
    char s[255];
    printf("Input line to reverse\n");
    scanf("%s", s);

    for (int i = strlen(s)-1; i >= 0; i--) {
        printf("%c", s[i]);
    }

    return 0;
}