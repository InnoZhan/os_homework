#include <stdio.h>

int main() {
	FILE *r_file = fopen("/dev/random", "r");
	FILE *w_file = fopen("ex1.txt", "w");

	char str[21];
	fgets(str, 20, r_file);
	fputs(str, w_file);
	str[20] = '\0';
	fclose(w_file);
	fclose(r_file);
	return 0;
}
