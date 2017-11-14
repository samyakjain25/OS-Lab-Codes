#include<stdio.h>

int main()
{
	int n,i,cTime=0,wTime=0,tTime=0,j,x,sum=0,time=0,sbegin=0,turntime=0;
	printf("No. of Processes : ");
	scanf("%d",&n);
	int creationTime[n],executionTime[n];	
	for(i=0;i<n;i++)
	{
		printf("Creation time for Process %d : ",i);
		scanf("%d",&creationTime[i]);
		printf("Execution time for Process %d : ",i);
		scanf("%d",&executionTime[i]);
	}
	printf("\tServiceTime\tCompletionTime\tWaitingTime\tTurnAroundTime\n");
	for(i=0;i<n;i++)
	{
		if(creationTime[i] > time)
		{
			sbegin = creationTime[i];
		}
		else
		{
			sbegin = time;		
		}
		wTime = sbegin - creationTime[i];
		cTime = sbegin + executionTime[i];
		time  = cTime;
		turntime = wTime + executionTime[i];
		printf("Process %d :\t",i);
		printf("%d\t\t%d\t\t%d\t\t%d\n",sbegin,cTime,wTime,turntime);
		
	}
}
