#include <signal.h>

int main() {
	pid_t process_id = fork();
	if(process_id == 0) {
		while(1) {
			printf("I'm alive!\n");
			sleep(1);
		}
	} else {
		sleep(10);
		kill(process_id, SIGTERM);
	}
}
