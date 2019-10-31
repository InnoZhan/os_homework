#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
	struct stat src_s;
	struct stat dest_s;
	char *string = "This is a nice day";
	char *addr_src;
	char *addr_dest;
	int src = open("ex1.txt", O_RDWR);
	int dest = open("ex1.memcpy.txt", O_RDWR);
	fstat(src, &src_s);
	fstat(dest, &dest_s);
	int src_size = src_s.st_size;
	int dest_size = dest_s.st_size;
	addr_src = mmap(NULL, src_size, PROT_READ, MAP_SHARED, src, 0);
	addr_dest = mmap(NULL, dest_size, PROT_WRITE, MAP_SHARED, dest, 0);
	ftruncate(dest, strlen(addr_src)*sizeof(char));
	memcpy(addr_dest, addr_src, src_size);
	close(src);
	close(dest);
	return 0;
}
