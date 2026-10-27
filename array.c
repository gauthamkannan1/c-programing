#include<stdio.h>
void main()
{
int a[50],s,i,e,p;
printf("Enter the Size of the array\n");
scanf("%d",&s);
printf("Enter the elements\n");
for(i=0;i<s;i++)
scanf("%d",&a[i]);
printf("Enter the position where element to be inserted\n");
scanf("%d",&p);
printf("Enter the element to be inserted\n");
scanf("%d",&e);
if(p<=0||p>s+1)
printf("invalid Option");
else
{
for(i=s-1;i>=p-1;i--)
{
a[i+1]=a[i];
}
a[p-1]=e;
s++;
}
printf("The array is:");
for(i=0;i<s;i++)
printf(" %d",a[i]);
}

