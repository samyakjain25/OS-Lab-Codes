#include<bits/stdc++.h>
#include <pthread.h>	
#include <algorithm>
using namespace std;
int burst[5],burstcopy[5];
int arrival[5] = {0,4,8,12,16};
int quanta = 2; 
int Time=0,in,comp[5];
int diff = 4,index1=0;
void* generate(void* vargp)
{
	for(int i =0 ; i<5;i++)
	{	burst[i]=(rand() % 10) + 1;
		burstcopy[i] = burst[i];
		printf("burst = %d\n",burst[i]);
	}	
}

void* strn(void* vargp)
{
	int min=10000,x,j,i;
	printf("Completion Time\n");
	for(j=0;j<5;j++)
	{	
		//time = time+diff;
		index1++;
		while(max_element(burstcopy,burstcopy+index1)>0 && Time<(index1)*(4))		
		{	min = 1000;
			for(i =0;i<index1;i++)
			{
				if(burstcopy[i]<min && burstcopy[i]>0)
				{
					in  = i;
					min = burstcopy[i];
				}
			}
			if(burstcopy[in]>=quanta)
			{
					//comp[in] = comp[in] + quanta;
					burstcopy[in] = burstcopy[in] - quanta;
					if(index1*4>Time && index1*4 - Time<quanta)
					{
						Time = Time + 1;
					}
					else					
					Time = Time+quanta;
					
					if(burstcopy[in]==0)
					{
						comp[in] =Time;	
					}
			}
			else
			{	
				Time = Time + burstcopy[in];
				burstcopy[in]=0;				
				comp[in] =Time;		
			}
		}

	}
	for(j=0;j<5;j++)
		printf("%d\n",comp[j]);
}

int  main()
{
	pthread_t t1,t2;
	pthread_create(&t1, NULL, generate, NULL);
	pthread_create(&t2, NULL,strn , NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

}
