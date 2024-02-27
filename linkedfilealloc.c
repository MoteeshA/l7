
#include <stdio.h>

int main(){
    int mem[50], i, j, start, len;
    int n, nq[20], a;

    for(i = 0; i < 50; i++){
        mem[i] = 0;
    }

    printf("Enter how many blocks are already allocated : ");
    scanf("%d", &n);

    printf("Enter the blocks that are allocated : ");
    for(i = 0; i < n; i++){
        scanf("%d", &a);
        if(a < 50){
            mem[a] = i;
        }
    }

    x:
        printf("Enter index starting block and length : ");
        scanf("%d %d", &start, &len);

        if(mem[start] == 0){
            for(i = start; i < start + len; i++){
                if(mem[i] != 0){
                    printf("%d block is already allocated\n", i);
                    len++;
                }
                else{
                    mem[i] = 1;
                    printf("%d -----------------------> 1\n", i);
                }
            }
        }
        else{
            goto x;
        }
    
    return 0;
}