
#include <stdio.h>
#include <string.h>

char dname[20], fname[20][20];
int i, j, n, ch = 1;

int main(){
    printf("Enter the directory name : ");
    scanf("%s", dname);

    printf("Enter the number of files : ");
    scanf("%d", &n);

    for(i = 0;i < n; i++){
        printf("Enter the file name : ");
        scanf("%s", fname[i]);
    }

    while(ch){
        printf("Do you want to enter another file (yes-1 / no-0) : ");
        scanf("%d", &ch);

        if(ch == 1){
            printf("Enter the file name : ");
            scanf("%s", fname[i++]);
        }
    }

    printf("\nDirectory Name : %s\n", dname);
    for(j = 0; j < i; j++){
        printf("%s\n", fname[j]);
    }

    return 0;
}
