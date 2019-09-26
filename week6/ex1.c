#include <sys/types.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

char* str1 = "Hello world!";
int msgsize = 13;
int main() {
	int pipe_end[2];

	if (pipe (pipe_end) < 0) {
		exit(1);	
	}

	char str2[msgsize];
	
	write(pipe_end[1], str1, msgsize);
	read(pipe_end[0], str2, msgsize);
	printf("string 1: %s\n", str1);
	printf("string 2: %s\n", str2);
	
	return 0;
}
