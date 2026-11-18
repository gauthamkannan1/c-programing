#include<stdio.h>
#define MAX 20
int parent[MAX];
int rank[MAX];
void Creation(int n)
{
int i;
for(i=0;i<n;i++)
{
parent[i]=i;
rank[i]=0;
}
printf("Disjoined sets created successfully\n");
}
int find(int x)
{
if(parent[x]!=x)
parent[x]=find(parent[x]);
return parent[x];
}
void Union(int x,int y)
{
int rootX=find(x);
int rootY=find(y);
if(rootX==rootY)
{
printf("both elements belong to the same set.\n");
return;
}
if(rank[rootX]<rank[rootY])
{
parent[rootX]=rootY;
}
else if(rank[rootY]>rank[rootY])
{
parent[rootY]=rootX;
}
else
{
parent[rootY]=rootX;
rank[rootX]++;
}
printf("Union operation completed successfully\n");
}
void display(int n)
{
int i;
printf("\nElement\tparent\tRepresentative\n");
for(i=0;i<n;i++)
{printf("%d\t%d\t%d\n",
i,parent[i],find(i));
}
}
int main()
{
int n,choice,x,y;
printf("Enter number of elements:");
scanf("%d",&n);
if(n<=0||n>MAX)
{
printf("invalid numberof elements!\n");
return 0;
}
do
{
printf("\n------DISJOINT SET ADT------\n");
printf("1.Create\n");
printf("2.Union\n");
printf("3.Find\n");
printf("4.Display\n");
printf("5.Exit\n");
printf("Enter your choice");
scanf("%d",&choice);
switch(choice)
{
case 1:Creation(n);
	break;
case 2:printf("Enter two elements:");
	scanf("%d%d",&x,&y);
	if(x>=0&&x<n&&y>=0&&y<n)
	Union(x,y);
	else
	printf("Invalid elements!\n");
	break;
case 3:printf("Enter elements to find:");
	scanf("%d",&x);
	if(x>=0&&x<n)
	printf("Representative of %d is %d\n",x,find(x));
	else
	printf("invalid choice!\n");
	break;
case 4:display(n);
	break;
case 5:printf("Exiting program...\n");
       break;
default:printf("invalid choice\n");
}
}while(choice!=5);
return 0;
} 					
	
	

