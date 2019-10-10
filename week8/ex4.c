#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>

int main() {
	int mem_size = 10 * 1024 * 1024;
	struct rusage usage;
	for (int i = 0; i < 10; i++) {
		//int *a = calloc(1, mem_size);
		int *a = malloc(mem_size);
		memset(a, 0, mem_size);
		getrusage(RUSAGE_SELF, &usage);
		printf("%ld\n", usage.ru_maxrss);
		sleep(1);
	}
	return 0;
}
