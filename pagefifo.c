#include <stdio.h>

int page[50], frame[10];

int main() {
    int n, fn;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("\nEnter replacement string: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &page[i]);

    printf("\nEnter the number of frames: ");
    scanf("%d", &fn);

    printf("\nPAGE STRING | FRAMES\t\t| PAGE FAULTS\n");
    printf("----------------------------------------\n");

    int pagefault = 0;
    int inFrame;

    for (int i = 0; i < n; i++) {
        inFrame = 0;
        printf("%d\t\t| ", page[i]);

        for (int j = 0; j < fn; j++) {
            printf("%d ", frame[j]);
            if (frame[j] == page[i]) {
                inFrame = 1;
                break;
            }
        }

        if (!inFrame) {
            int j = 0;
            frame[j] = page[i];
            pagefault++;
        }

        printf("\t\t| %d\n", pagefault);
    }

    printf("\nTotal Page Faults: %d\n", pagefault);

    return 0;
}
