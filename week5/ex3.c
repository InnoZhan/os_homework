#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <limits.h>

int stuff = 0;
const int max = INT_MAX;

void *producer_func(void *vargp) {
	while(1) {
		if (stuff < max) {
			stuff++;
		} else {
			while (stuff >= max) {
				sleep(0.1);
			}
		}
	}
}

void *consumer_func(void *vargp) {
	while(1) {
		if (stuff > 0) {
			stuff--;	
		} else {
			while (stuff = 0) {
				sleep(0.1);			
			}
		}
	}
}

void *timer_func(void *vargp) {
	while(1) {
		sleep(5);
		printf("%d", stuff);
	} 
}

int main() {
	pthread_t producer;
	pthread_t consumer;
	pthread_t timer;

	pthread_create(&producer, NULL, producer_func, NULL);
	pthread_create(&consumer, NULL, consumer_func, NULL);
	pthread_create(&timer, NULL, timer_func, NULL);
	pthread_exit(NULL);
	return 0;
}

