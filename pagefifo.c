#include <stdio.h>

int pages[50], frame[10];

int main() {
    int n, i, j = 0, k, fn, count = 0, maincounter = 0, pageFaults = 0;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the reference string\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &fn);

    for (i = 0; i < fn; i++)
        frame[i] = -1;

    printf("\nReference String\tPage Frames\tPage Faults\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t", pages[i]);
        count = 0;
        for (k = 0; k < fn; k++) {
            if (frame[k] == pages[i]) {
                count = 0; // If the page is already in the frame, set count to 0
                break;     // Exit the loop
            }
        }
        if (count == fn) {
            frame[j] = pages[i];
            j = (j + 1) % fn;
            pageFaults++;
        }
        for (k = 0; k < fn; k++) {
            printf("%d\t", frame[k]);
        }
        printf("\t\t%d\n", pageFaults);
    }

    printf("Total Page Faults: %d\n", pageFaults);

    return 0;
}
