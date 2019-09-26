#include <signal.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	int pipe_end[2];

	int ex = 0;

	if (ex = pipe(pipe_end)) {
		fprintf(stderr, "Pipe failed: %d\n", ex);
		exit(ex);
	}

	pid_t process_id1 = fork();

	if (process_id1 > 0) {
		pid_t process_id2 = fork();
		if (process_id2 > 0) {
			close(pipe_end[0]);
			FILE *file = fdopen(pipe_end[1], "w");			
			printf("Parent sends second childs' process id to the first\n");
			fprintf(file, "%d", process_id2);
			fclose(file);
			int status = 0;
			printf("Parent listening second childs' status change\n");		
			waitpid(process_id2, &status, 0);
			printf("Parent got second childs' status = %d\n", status);
			exit(0);
		}
		if (process_id2 == 0) {
			close(pipe_end[0]);
			close(pipe_end[1]);
			printf("Second child has started\n");
			while(1) {
				printf("Still alive\n");
				sleep(1);
			}
		}
	}
	if (process_id1 == 0) {
		close(pipe_end[1]);
		pid_t process_id2;
		printf("First child has started\n");
		FILE *file = fdopen(pipe_end[0], "r");
		fscanf(file, "%d", &process_id2);		
		fclose(file);
		printf("First child recived process id of the second child = %d\n", process_id2);
		printf("First child goes to sleep\n");		
		sleep(5);
		printf("First child sends SIGSTOP command to the second child\n");
		kill(process_id2, SIGSTOP);
	}
}
