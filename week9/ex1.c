#include <stdlib.h>
#include <stdio.h>

const int frame_size = 10;

typedef struct frame {
	int ref;
	int number;
	int priority;
} frame;

int main() {

	int hit = 0;
	int miss = 0;

	FILE *file = fopen("input.txt", "r");

	frame *frames = calloc(frame_size, sizeof(frame));

	for (int i = 0; i < frame_size; i++) {
		frames[i].priority = 0;
		frames[i].number = 0;
		frames[i].ref = 0;
	}

	int frame_num = 0;

	while (fscanf (file, "%d", &frame_num) != EOF) {

		int temp = hit;
		
		for (int i = 0; i < frame_size; i++) {
			frames[i].priority = frames[i].priority >> 1;
		
			if (frames[i].ref == 1 && frames[i].number == frame_num) {
				hit++;
				frames[i].priority += 128;
				i = frame_size;
			}
 		}

		if (temp == hit) {
			int min_index = 0;
			int j = 0;
			miss++;

			for (j = 0; j < frame_size; j++) {
				if (frames[j].ref == 0) {
					min_index = j;
					j = frame_size + 1;
				}
			}

			if (j == frame_size) { 
				int min = 256;
				for (int j = 0; j < frame_size; j++) {
					if (frames[j].priority < min) {
						min = frames[j].priority;
						min_index = j;
					}
				}
			}

			frames[min_index].number = frame_num;
			frames[min_index].priority = 128;
			frames[min_index].ref = 1;
		}
    }

    float ration = (float)hit/(float)miss;
    printf("hit: %d\nmiss: %d\nhit/miss: %f", hit, miss, ration);

    fclose(file);
}