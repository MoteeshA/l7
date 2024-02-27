

#include <stdio.h>

int pages[50], frame[10];

int main(){
    int n, i, j = 0, k, fn, count = 0, maincounter = 0;

    printf("Enter the number of pages : ");
    scanf("%d", &n);

    printf("Enter the reference string\n");
    for(i = 0; i < n; i++){
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames : ");
    scanf("%d", &fn);

    for(i = 0; i < fn; i++)
        frame[i] = -1;
    printf("\nReference String\tPage Frames\n");
    for(i = 0; i < n; i++){
        printf("%d\t\t", pages[i]);
        count = 0;
        for(k = 0; k < fn; k++){
            if(frame[k] != pages[i]){
                count++;
            }
        }
        if(count == fn){
            frame[j] = pages[i];
            j = (j+1)%fn;
        }
        for(k = 0; k < fn; k++){
                printf("%d\t", frame[k]);
        }
        printf("\n");
    }

    return 0;
}

