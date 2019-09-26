#include <sys/types.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void pipe_read(int file) {
	FILE *text;
	text = fdopen(file, "r");
	char c;
	while ((c = fgetc(text)) != EOF) {
		printf("%c", c);	
	}
	fclose(text);
	exit(0);
}

int main() {
	int pipe_end[2];
	pipe (pipe_end);
	pid_t process_id = fork();

	if(process_id == 0) {
		pipe_read(pipe_end[0]);
	}
	
	FILE *file = fdopen(pipe_end[1], "w");
	fprintf(file, "%s", "Hello, fork!\n");
	fclose(file);
	return 0;
}
