#include <stdio.h> 
#include <stdlib.h>

int main() {
	int n = 0;
	printf("Insert number of elements in the array\n");
	scanf("%d", &n);
	int *a = (int *)calloc(n,sizeof(int));
	for (int i = 0; i < n; i++) {
		a[i] = i;	
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);	
	}
	printf("\n");
	free(a);
	return 0;	
}
