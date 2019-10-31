#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
	struct stat s;
	char *string = "This is a nice day";
	char *addr;
	int file = open("ex1.txt", O_RDWR);
	fstat(file, &s);
	int size = s.st_size;
	addr = mmap(NULL, size, PROT_WRITE, MAP_SHARED, file, 0);
	ftruncate(file, strlen(string)*sizeof(char));
	strcpy(addr, string);
	close(file);
	return 0;
}
