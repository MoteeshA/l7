#include <stdio.h>

int page[10],frame[10];

int main(){
	int n;
	int j=0;
	int i;
	int count=0;
	printf("enter ht number of pages: ");
	scanf("%d",&n);

	printf("\nEntert the referance string");
	for(int i=0;i<n;i++) 
	scanf("%d",&page[i]);
	int fn;
	printf("\nEnter thr number of frames:");
	scanf("%d",&fn);
	
	
	for(int i=0;i<fn;i++)
		frame[i]=-1;
	int faults=0;
	printf("PAGE\tPAGEFAULT\n");
    
	for(int i=0;i<n;i++){
		printf("%d\t\t",page[i]);
		
		int count=0;
		for(int k=0;k<fn;k++){
			if(frame[k]!=page[i]){
				count++;
			}
	}
	if (count==fn){
		
		frame[j]=page[i];
		j=(j+1)%fn;
		faults++;
	}
	for(int k=0;k<fn;k++){
		printf("%d\t",frame[k]);
	}
	printf("\n");
	}
	printf("faults: %d",faults);
	return 0;
}
