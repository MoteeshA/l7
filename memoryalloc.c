// #include <stdio.h>

// #define MAX_MEMORY_SIZE 50
// #define MAX_PARTITION_SIZE 10

// int memory[MAX_MEMORY_SIZE], partitions[MAX_PARTITION_SIZE];
// int i, j, k;
// int numpartitions = 0;

// void initializevalues(){
//     for(i = 0; i < MAX_MEMORY_SIZE; i++)
//         memory[i] = -1;
//     for(i = 0; i < MAX_PARTITION_SIZE; i++)
//         partitions[i] = -1;
// }

// int firstfit(int size){
//     for(i = 0; i < MAX_MEMORY_SIZE; i++){
//         if(memory[i] == -1){
//             for(j = i; j < MAX_MEMORY_SIZE && memory[j] == -1; j++){
//                 if(j-i+1 == size){
//                     for(k = i; k < j+1; k++){
//                         memory[k] = size;
//                     }
//                     partitions[numpartitions++] = i;
//                     return 1;
//                 }
//             }
//             i = j;
//         }
//     }
//     return 0; 
// }

// int bestfit(int size){
//     int bestFitSize = MAX_MEMORY_SIZE+1;
//     int bestFitIndex = -1;

//     for(i = 0; i < MAX_MEMORY_SIZE; i++){
//         if(memory[i] == -1){
//             int currentsize = 0;
//             for(j = i; j < MAX_MEMORY_SIZE && memory[j] == -1; j++){
//                 currentsize++;
//             }
//             if(currentsize >= size && currentsize < bestFitSize){
//                     bestFitSize = currentsize;
//                     bestFitIndex = i;
//             }
//             i = j;
//         }
//     }

//     if(bestFitIndex != -1){
//         for(i = bestFitIndex; i < bestFitIndex + size; i++){
//             memory[i] = size;
//         }
//         partitions[numpartitions++] = bestFitIndex;
//         return 1;
//     }
//     return 0; 
// }

// int worstfit(int size){
//     int worstFitSize = MAX_MEMORY_SIZE+1;
//     int worstFitIndex = -1;

//     for(i = 0; i < MAX_MEMORY_SIZE; i++){
//         if(memory[i] == -1){
//             int currentsize = 0;
//             for(j = i; j < MAX_MEMORY_SIZE && memory[j] == -1; j++){
//                 currentsize++;
//             }
//             if(currentsize >= size && currentsize > worstFitSize){
//                     worstFitSize = currentsize;
//                     worstFitIndex = i;
//             }
//             i = j;
//         }
//     }

//     if(worstFitIndex != -1){
//         for(i = worstFitIndex; i < worstFitIndex + size; i++){
//             memory[i] = size;
//         }
//         partitions[numpartitions++] = worstFitIndex;
//         return 1;
//     }
//     return 0; 
// }

// void deallocate(int part){
//     if(partitions[part] == -1){
//         printf("\nDeallocation unsuccessful\n");
//         return 0;
//     }
//     int rem = memory[partitions[part]] + partitions[part];
//     for(i = part; i < rem; i++){
//         memory[i] = -1;
//     }
//     partitions[part] = -1;
//     printf("\nDeallocation was Successful\n");
// }


#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY_SIZE 50
#define MAX_PARTITION_SIZE 10

int memory[MAX_MEMORY_SIZE], partitions[MAX_PARTITION_SIZE], num_partitions = 0;
int i, j, k;

void initializeMemory(){
    for(i = 0; i < MAX_MEMORY_SIZE; i++)
        memory[i] = -1;
    for(i = 0; i < MAX_PARTITION_SIZE; i++){
        partitions[i] = -1;
    }
}

int firstfit(int size){
    for(i = 0; i < MAX_MEMORY_SIZE; i++){
        for(j = i; j < MAX_MEMORY_SIZE && memory[j] == -1; j++){
            if(j-i+1 == size){
                for(k = i; k < i + size; k++){
                    memory[k] = size;
                }
                partitions[num_partitions++] = i;
                return 1;
            }
        }
        i = j;
    }
    return -1;
}

int bestfit(int size){
    int bestFitSize = MAX_MEMORY_SIZE+1;
    int bestFitIndex = -1;
    int currentsize;
    for(i = 0; i < MAX_MEMORY_SIZE; i++){
        currentsize = 0;
        for(j = i; j < MAX_MEMORY_SIZE && memory[j] == -1; j++){
            currentsize++;
        }
        if(currentsize >= size && currentsize < bestFitSize){
            currentsize = bestFitSize;
            bestFitIndex = i;
        }
        i = j;
    }

    if(bestFitIndex != -1){
        for(k = bestFitIndex; k < bestFitIndex+size; k++){
            memory[k] = size;
        }
        partitions[num_partitions++] = bestFitIndex;
        return 1;
    }
    return -1;
}

int worstfit(int size){
    int worstFitSize = -1;
    int worstFitIndex = -1;
    int currentsize;
    for(i = 0; i < MAX_MEMORY_SIZE; i++){
        currentsize = 0;
        for(j = i; j < MAX_MEMORY_SIZE && memory[j] == -1; j++){
            currentsize++;
        }
        if(currentsize >= size && currentsize > worstFitSize){
            currentsize = worstFitSize;
            worstFitIndex = i;
        }
        i = j;
    }

    if(worstFitIndex != -1){
        for(k = worstFitIndex; k < worstFitIndex+size; k++){
            memory[k] = size;
        }
        partitions[num_partitions++] = worstFitIndex;
        return 1;
    }
    return -1;
}

int deallocate(int part){
    if(partitions[part] != -1){
        int rem = memory[partitions[part]] + partitions[part];
        for(i = partitions[part]; i < rem; i++){
            memory[i] = -1;
        }
        partitions[part] = -1;
        return 1;
    }
    else{
        printf("\nDeallocation unsuccessful\n");
        return -1;
    }
}

void display(){
    for(i = 0; i < MAX_MEMORY_SIZE; i++){
        if(memory[i] == -1)
            printf("*");
        else{
            printf("X");
        }
    }
}

int main(){
    initializeMemory();

    int choice, size, part, count;

    while(1){
        printf("\nMemory Allocation Techniques\n");
        printf("1. First Fit\n2. Best Fit\n3. Worst Fit\n4. Deallocate Memory\n5. Display Memory\n6. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter Process Size : ");
                scanf("%d", &size);
                if(firstfit(size) == -1)
                    printf("Allocation Failed! Not Enough Memory\n");
                else
                    printf("Allocation Successful\n");
                break;

            case 2:
                printf("\nEnter Process Size : ");
                scanf("%d", &size);
                if(bestfit(size) == -1)
                    printf("Allocation Failed! Not Enough Memory\n");
                else
                    printf("Allocation Successful\n");
                break;

            case 3:
                printf("\nEnter Process Size : ");
                scanf("%d", &size);
                if(worstfit(size) == -1)
                    printf("Allocation Failed! Not Enough Memory\n");
                else
                    printf("Allocation Successful\n");
                break;

            case 4:
                count = 0;
                printf("\n");
                for(int i = 0; i < MAX_PARTITION_SIZE; i++){
                    if(partitions[i] >= 0 && partitions[i] < MAX_MEMORY_SIZE){
                        count++;
                        printf("Part %d : Size %d\n", i+1, memory[partitions[i]]);
                    }
                }
                printf("Currently there are %d parts to choose from\n", count);
                printf("Enter the part that you want to deallocate : ");
                scanf("%d", &part);

                deallocate(part-1);
                break;

            case 5:
                display();
                break;

            case 6:
                exit(1);

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}