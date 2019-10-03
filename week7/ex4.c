#include <stdio.h>

void * realloc(void * ptr, int size) {
	if (ptr == NULL) {
		return malloc(size);
	} else {
		if (size == 0) {
			free(ptr);
			return NULL;
		} else {
			int min = 0;
			if (size > sizeof(ptr)) {
				min = sizeof(ptr); 
			} else {
				min = size;
			}
			void * new_ptr = malloc(min);
			memcpy(new_ptr, ptr, min);
			free(ptr);
			return new_ptr;	
		}
	}
}

int main(){
	char * h = malloc(15); 
	memcpy(h, "Hello world!\n", 20);
	char * g = realloc(h, 20);
	printf("%s", g);
}
