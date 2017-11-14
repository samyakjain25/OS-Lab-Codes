#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,j,temp,x,flag=0,k,max=-2,index;
	cout<<"Page Slots :";
	cin>>n;
	int arr[100],page[n],count[n];
	cout<<"Number of Page references :";
	cin>>temp;
	for(i=0;i<n;i++)
	{
		count[i]=1000;
		page[i]=-1;
	}
	for(i=0;i<temp;i++)
	{
		cin>>arr[i];
	}
	for(i=0;i<temp;i++)
	{
		flag=0;
		max = -2;
		for(j=0;j<n;j++)
		{
			if(page[j]==arr[i])
			{
				flag=1;
				count[j]=-1;
				for(k=0;k<n;k++)
				{
					count[k]++;
				}
				flag=1;
				break;	
			}
		}
		if(flag==1)
		{
			cout<<"Page "<<arr[i]<<" already present"<<endl;
			for(j=0;j<n;j++)
			{
				cout<<page[j]<<" ";
			}
			cout<<endl<<endl;
			continue;
		}
		else
		{
			cout<<"Page Fault :"<<arr[i]<<endl;
			for(j=0;j<n;j++)
			{
				if(count[j]>max)
				{
					max = count[j];
					index = j;
				}
			}
			page[index] = arr[i];
			count[index]=-1;
			for(k=0;k<n;k++)
			{
				count[k]++;
			}
			for(j=0;j<n;j++)
			{
				cout<<page[j]<<" ";
			}
			cout<<endl<<endl;
			continue;
		}

	}
}
