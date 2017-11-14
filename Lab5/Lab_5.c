#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int visited[100]={0};
int graph[80][80]={0};
int cycle = 0;
int arr[76]={0};
int stack[76]={0};
int stInd=0;
int flag=0;
void DFS(int i)
{
   // printf("APPLYING DFS ON %d\n",i);

    if(visited[i]==1)
    {
        return;
    }
    stack[stInd++]=i;
    visited[i]=1;
    int j;
    for(j=0;j<76;j++)
    {
        if(graph[i][j]==1)
        {
            if(visited[j]==0)
            {
                DFS(j);
            }
            else if((visited[j]==1) && stInd>=0)
            {
                    printf("Cycle detected\n");
                    stInd--;
                    while(stack[stInd]!=j && stInd>-1)
                    {
                        printf("%d\n",stack[stInd]);
                        stack[stInd]=0;
                        stInd--;
                    }
                    if(stInd)
                        printf("%d\n",stack[stInd]);
                    return;
            }
        }
    }
}

int main()
{
	FILE *input,*output;
	char line[10];
	char* v1,*v2;
	int p,r,flag,k,i,j,flag1,count=0,x=0;
	input = fopen("read.csv","r");
	while(fgets(line,sizeof(line),input)!=NULL)
	{
//	    printf("Line = %s\n",line);
		v1 = strtok(line,",");
		v2 = strtok(NULL,",");
		if(v1[0]>='a' && v1[0]<='z')
		{
			p = v1[0]-'a';
			r = atoi(v2);
			graph[p][r+25]=1;
		}
		else
		{
			p = atoi(v1);
			r = v2[0]-'a';
			graph[p+25][r]=1;
		}


//		for(i =0;i<76;i++)
//		{
//			for(j=0;j<76;j++)
//			{
//				printf("%d",graph[i][j]);
//			}
//			printf("\n");
//		}

		//printf("R = %d\t P = %d\n",r,p);

	}
	for(i=0;i<26;i++)
	{
        for(j=0;j<76;j++)
        {
			if(graph[i][j]==1 && visited[j]==0)
			{
                stInd=0;
                DFS(i);
			}
		}

	}
	return 0;
}
