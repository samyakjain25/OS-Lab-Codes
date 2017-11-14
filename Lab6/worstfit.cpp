#include<iostream>
using namespace std;

int main()
{
	int block,size1,i,j,memory,free,pid,amount,temp1,temp2=0,diff,maxdiff =-1,index,add=0;
	cin>>size1;
	int a[100][2] = {0};
	memory = 0;
	free = size1;
	i=0;
	block = 1;
	while(1)
	{
		cin>>pid>>amount;
		maxdiff =-1;
		if(amount>0 && free >= amount)
		{	temp2 =0;
			for(i=0;i<100;i++)
			{
				if(a[i][0] == 0 && (a[i][1] ==0 || a[i][1] >= amount))
				{
					temp1 = a[i][1];
					if(temp1>=amount)
					{
						diff = temp1-amount;
						if(diff>maxdiff)
						{
							maxdiff = diff;
							index = i;
						}
					}
					else if(temp1==0 && maxdiff==-1)
					{
                        index = i;
						temp2 =1;
						break;
					}
					else if(temp1==0 && maxdiff!=-1)
                    {
                        if(a[index][1]<free-a[index][1])
                        {
                        	index = i;
                            temp2 =1;
                            break;
                        }
                        else
                        {
                            temp2=1;
                            break;
                        }
                    }
				}
				if(temp2 ==1)
					break;
			}
			if(a[index][1]-amount==0 || a[index][1]==0)
			{
			a[index][0] = pid;
			a[index][1] = amount;
			memory = memory + amount;
			add =0;
			for(i=0;i<index;i++)
				add = add+a[i][1];
			free = free- amount;
			block = 0;
			}
			else
			{
				add = 0;
				for(i=0;i<index;i++)
					add = add+a[i][1];
				temp1 = a[index+1][1];
				temp2 = a[index+1][0];
				a[index+1][1] = a[index][1]-amount;
				a[index+1][0] = 0;
				a[index][0] = pid;
				a[index][1] = amount;
				memory = memory + amount;
				free = free- amount;
				block = 0;
				for(i = 99;i>index+2;i--)
				{
					a[i][1] = a[i-1][1];
					a[i][0] = a[i-1][0];
				}
				a[i][1] = temp1;
				a[i][0] = temp2;
	//			for(i =0;i<10;i++)
	//				for(j =0 ;j<2;j++)
						//cout<<"A"<<i<<j<<" = "<<a[i][j]<<endl;
			}
			for(j=0;j<99;j++)
			{
				if(j==0 && a[j][0]==0 && a[j+1][0]!=0)
				{
					block++;
				//	cout<<j<<" "<<block<<endl;
					continue;
				}
				if(a[j][0] == 0 )
				{
					if(a[j-1][0]==0 && a[j+1][0]==0)
						;
					else
					{
						block++;
						//cout<<j<<" "<<block<<endl;
					}
				}
			}
			cout<<"Address = "<<add<<"K"<<endl;
			cout<<"Free = "<<free<<"K  ";
			cout<<"Blocks = "<<block<<" ";
			cout<<"Avg. Size = "<<free/block<<"K"<<endl;



		}
		else if(amount ==0)
		{

			for(i=0;i<100;i++)
			{
				if(a[i][0]==pid)
				{
					add = 0;
					for(j=0;j<i;j++)
						add = add+a[j][1];
					a[i][0] = 0;
					free = free+a[i][1];
					block = 0;
					for(j=0;j<99;j++)
					{
						if(j==0 && a[j][0]==0 && a[j+1][0]!=0)
						{
							block++;
							//cout<<j<<" "<<block<<endl;
							continue;
						}
						if(a[j][0] == 0 )
						{
							if(a[j-1][0]==0 && a[j+1][0]==0)
								;
							else
							{
								block++;
								//cout<<j<<" "<<block<<endl;
							}
						}
					}
					cout<<"Address = "<<add<<"K"<<endl;
					cout<<"Free = "<<free<<"K  " ;
					cout<<"Blocks = "<<block<<" ";
					cout<<"Avg. Size = "<<free/block<<"K"<<endl;

					break;
				}
			}
		}


	}





}
