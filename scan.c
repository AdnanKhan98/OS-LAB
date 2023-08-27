#include<stdio.h>
#include<stdlib.h>

void main() {
	int n,curr;
	printf("Enter the number of requests in the request queue:");
	scanf("%d",&n);
	printf("Enter the position of the head:");
	scanf("%d",&curr);
	printf("enter the request queue sequence:");
	int rq[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&rq[i]);
	}
	printf("\n");
	int total=0;
	for(int i=0;i<n-1;i++)
	for(int j=0;j<n-i-1;j++)
	{
		if(rq[j]>rq[j+1])
		{
			int temp=rq[j];
			rq[j]=rq[j+1];
			rq[j+1]=temp;
		}
	}
	int currenindex;
	for(int i=0;i<n;i++)
	{
		if(rq[i]>=curr)
		{
			total+=abs(curr-rq[i]);
			curr=rq[i];
			currenindex=i;
		}
	}
	for(int i=currenindex-1;i>=0;i--)
	{
		total+=abs(curr-rq[i]);
		curr=rq[i];
	}
	printf("%d",total);
}
