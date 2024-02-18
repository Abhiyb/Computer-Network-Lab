#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void goBackNArq(int frames, int wz) {
    int i = 0;
    while (i < frames) {
        for (int temp = i; temp < i + wz && temp < frames; temp++) {
            printf("SENDING FRAME %d\n", temp);
        }
        for (int j = 0; j < wz && i < frames; j++) {
            int r = rand() % 2; // Randomly generate 0 or 1
            if (r == 1) {
                printf("ACK Received for frame %d\n", i);
                i++;
            } else {
                printf("ACK NOT RECEIVED for frame %d \n", i);
                break;
            }
        }
        printf("RETRANSMITTING WINDOW\n");
    }
}

void selective(int frames, int wz) {
    int i = 0;
    while (i < frames) {
        for (int temp = i; temp < i + wz && temp < frames; temp++) {
            printf("SENDING FRAME %d\n", temp);
        }
        for (int j = 0; j < wz && i < frames; j++) {
            int r = rand() % 2; // Randomly generate 0 or 1
            if (r == 1) {
                printf("ACK Received for frame %d\n", i);
                i++;
            } else {
                printf("ACK NOT RECEIVED for frame %d \n", i);
                printf("Sending Back frame %d\n", i);
                printf("ACK  RECEIVED for frame %d\n", i);
                i++;
            }
        }
        printf("RETRANSMITTING WINDOW\n");
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int frames, wz;
    printf("Enter frames and window size: ");
    scanf("%d %d", &frames, &wz);
    printf("\nGo-Back-N ARQ:\n");
    goBackNArq(frames, wz);
    
    printf("\nSelective Repeat ARQ:\n");
    selective(frames, wz);
    return 0;
}
