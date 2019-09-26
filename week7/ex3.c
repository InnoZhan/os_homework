#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

static void handle(int i) {
	fprintf(stderr, "\nCtrl-c is pressed\n");
	exit(0);
}

int main(int argc, char *argv[]) {

	signal(SIGINT, handle);

	while (1) {
	}
}
