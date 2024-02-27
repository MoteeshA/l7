#include<stdio.h>
int absoluteValue(int);
void main(){
	int queue[25],n,headposition,i,j,k,seek=0,maxrange,difference,temp,queue1[20],queue2[20],temp1=0,temp2=0;
	float averageseektime;
	printf("enter the maximum range of disk:");
	scanf("%d",&maxrange);
	printf("enter the number of queue request:");
	scanf("%d",&n);
	printf("enter the headposition");
	scanf("%d",&headposition);
	printf("enter the disk positions to be read(queue)");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&temp);
		if(temp>headposition){
			queue1[temp1]=temp;
			temp1++;
			}
			else{
				queue2[temp2]=temp;
				temp2++;
				}
				}
				
	for(i=0;i<temp1-1;i++)
	{
		for(j=i+1;j<temp1;j++)
		{
			if(queue1[i]>queue1[j])
			{
				temp=queue1[i];
				queue1[i]=queue1[j];
				queue1[j]=temp;
				}
			}
		}
	
	for(i=0;i<temp2-1;i++)
	{
		for(j=i+1;j<temp2;j++)
		{
			if(queue2[i]<queue2[j])
			{
				temp=queue2[i];
				queue2[i]=queue2[j];
				queue2[j]=temp;
				}
			}
		}	
	
	for(i=1,j=0;j<temp1;i++,j++){
		queue[i]=queue1[j];	
		}
		queue[i]=maxrange;
		for(i=temp1+2,j=0;j<temp2;i++,j++){
			queue[i]=queue2[j];
			}
			queue[i]=0;
			queue[0]=headposition;
			for(j=0;j<=n;j++){
			difference=absoluteValue(queue[j+1]-queue[j]);
			seek=seek + difference;
			printf("disk moves from %d to %d with seek time %d\n",queue[j],queue[j+1],difference);
			}
			averageseektime=seek/(float)n;
			printf("seek time=%d\n",seek);
			printf("average seek time = %f\n",averageseektime);
			}
			
	int absoluteValue(int x){
		if(x>0){
			return x;
			}
			else{
				return x*-1;
				}
				}
				
		
		
		
		
		
		
		
		
				
