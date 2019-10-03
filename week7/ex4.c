#include <stdio.h>

void * realloc(void * ptr, int size, int old_size) {
	if (ptr == NULL) {
		return malloc(size);
	} else if (size == 0) {
		free(ptr);
		return NULL;
	} else {
		int min = 0;
		if (size > old_size) {
			min = old_size; 
		} else {
			min = size;
		}
		void * new_ptr = malloc(size);
		memcpy(new_ptr, ptr, min);
		free(ptr);
		return new_ptr;	
	}
}

int main(){
	char * h = malloc(15);
	memcpy(h, "Hello world!\n", 15);
	char * g = realloc(h, 20, 15);
	printf("%s", g);
	return 0;
}
