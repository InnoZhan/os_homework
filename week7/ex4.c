#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
/*
	Other interrupts, except SIGUSR1 can't be handled
*/
static void handle(int i) {
	fprintf(stderr, "\nInterrupt %d\n", i);
	exit(0);
}

int main(int argc, char *argv[]) {

	signal(SIGUSR1, handle);
	signal(SIGKILL, handle);
	signal(SIGSTOP, handle);

	kill(getpid(), SIGUSR1);
	
	while (1) {
	}
}
