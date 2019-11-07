#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	char buffer[255];
	fgets(buffer, sizeof(buffer), stdin);
	char *mode = "w";	
	int input_shift = 0;
	if (argc > 1) {
		if (strcmp(argv[1], "-a") == 0) {
			mode = "a";
			input_shift = 1;		
		}	
	}
	for (int i = 1 + input_shift; i < argc; i++) {
		FILE *file = fopen(argv[i], mode);
		fputs(buffer, file);
		fclose(file);
	}
	printf("%s", buffer);
	return 0;
}
