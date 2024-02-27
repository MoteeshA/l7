#include <stdio.h>

// Function to find the index of the least recently used page in the frame
int findLRU(int age[], int n) {
    int lruIndex = 0, lruAge = age[0];

    for (int i = 1; i < n; i++) {
        if (age[i] < lruAge) {
            lruAge = age[i];
            lruIndex = i;
        }
    }

    return lruIndex;
}

int main() {
    int page[20], frame[20], age[20];
    int n;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the reference string: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &page[i]);
    }

    int fn;
    printf("Enter the number of frames: ");
    scanf("%d", &fn);

    for (int i = 0; i < fn; i++) {
        frame[i] = -1;
        age[i] = 0;
    }

    printf("REFER\tPAGE\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t", page[i]);

        int found = 0;

        // Check if the page is already in the frame
        for (int k = 0; k < fn; k++) {
            if (frame[k] == page[i]) {
                found = 1;
                age[k] = 0; // Reset age for the used page
            }
        }

        // Page fault, find the LRU index
        if (found == 0) {
            int lruIndex = findLRU(age, fn);
            frame[lruIndex] = page[i];
            age[lruIndex] = 0;
        }

        for (int k = 0; k < fn; k++) {
            printf("%d\t", frame[k]);
        }
        printf("\n");
    }

    return 0;
}
