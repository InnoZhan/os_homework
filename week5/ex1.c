#include <stdio.h>
#include <pthread.h> 
  
void *myThreadFun(void *vargp) 
{  
	int *x = (int *) vargp;
	printf("Some text ");
	printf("%d\n", *x);
	return NULL; 
} 
   
int main() 
{ 
	int n = 40;
	pthread_t thread_id; 
	for (int i = 0; i < n; i++) {
    		pthread_create(&thread_id, NULL, myThreadFun, &i); 
		printf("thread created\n");    		
		pthread_join(thread_id, NULL); 
	}
    	return 0; 
}

