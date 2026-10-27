#include<stdio.h>
void main()
{
int a[50],s,i,e,p;
printf("Enter the Size of the array\n");
scanf("%d",&s);
printf("Enter the elements\n");
for(i=0;i<s;i++)
scanf("%d",&a[i]);
printf("Enter the position of element to be deleted\n");
scanf("%d",&p);
if(p<=0||p>s+1)
printf("invalid Option");
else
{
for(i=p-1;i<=s-1;i++)
{
a[i]=a[i+1];
}
s--;
}
printf("The array after deletion:");
for(i=0;i<s;i++)
printf(" %d",a[i]);
}

