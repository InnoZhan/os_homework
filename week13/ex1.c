#include <stdio.h>
#include <stdlib.h>

int main() {
	int p, r, *E, *A, **C, **R;

	FILE *input = fopen("input_ok.txt", "r");
	FILE *output = fopen("output.txt", "w");

	fscanf(input, "%d\n", &p);
	fscanf(input, "%d\n", &r);

	E = calloc(r, sizeof(*E));
	A = calloc(r, sizeof(*A));

	C = calloc(p, sizeof(*C));
	R = calloc(p, sizeof(*R));
	int *finished = calloc(p, sizeof(int));
	for (int i = 0; i < p; i++) {
		C[i] = calloc(r, sizeof(*C[i]));
		R[i] = calloc(r, sizeof(*R[i]));	
	}
	
	for (int i = 0; i < r; i++) {
		fscanf(input, "%d", &E[i]);
	}	
	for (int i = 0; i < r; i++) {
		fscanf(input, "%d", &A[i]);
	}	
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < r; j++) {
			fscanf(input, "%d", &C[i][j]);
		}
	}
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < r; j++) {
			fscanf(input, "%d", &R[i][j]);
		}
	}

	int changed = 1;
	while (changed) {
		changed = 0;
		for (int i = 0; i < p; i++) {
			if (finished[i] == 0) {
				int granted = 1;
				for (int j = 0; j < r; j++) {
					if (A[j] < R[i][j]) {
						granted = 0;
					}
				}	
				if (granted) {
					for (int j = 0; j < r; j++) {
						A[j] += C[i][j];
						R[i][j] = 0;
					}
					finished[i] = 1;
					changed = 1;
					i = p;
				}
			}
		}
	}
	int broke = 1;
	for (int i = 0; i < p; i++) {
		if (finished[i] == 0) {
			broke = 0;
			fprintf(output, "Process %d is dedlocked\n", i);
		}
	}
	if (broke) {
		fprintf(output, "All processes are done\n");
	}
	fclose(input);
	fclose(output);
	return 0;
}
