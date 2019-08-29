#include <stdio.h>

void elka(int n) {
    for (int i = 1; i <= n; i++) {
        for(int j = 0; j < n - i; j++) {
            printf(" ");
        }
        for (int j = 0; j < 2*i - 1; j++) {
            printf("*");
        }

        printf("\n");
    }
}

void half_elka(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
};

void wall(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void wrong_elka(int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (i > n / 2) count--;
        else if ((i == n / 2) && (n % 2 == 0)) ;else count++;
        for (int j = 0; j < count; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int var, n;
    printf("1)\n");
    elka(6);
    printf("2)\n");
    half_elka(6);
    printf("3)\n");
    wall(6);
    printf("4)\n");
    wrong_elka(6);
    printf("choose picture of your preference\n");
    do {
        scanf("%d", &var);
    } while (var < 1 || var >4);
    printf("What height will it be? (1..50)\n");
    do {
        scanf("%d", &n);
    } while (var < 1 || var >50);
    switch (var) {
        case 1: elka(n); break;
        case 2: half_elka(n); break;
        case 3: wall(n); break;
        case 4: wrong_elka(n); break;
    }
    return 0;
}