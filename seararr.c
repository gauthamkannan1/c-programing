#include<stdio.h>
void main()
{
int a[50],s,i,f,g=0;
printf("Enter the Size of the array\n");
scanf("%d",&s);
printf("Enter the elements\n");
for(i=0;i<s;i++)
scanf("%d",&a[i]);
printf("Enter the element to be searched\n");
scanf("%d",&f);
for(i=0;i<s-1;i++)
{
if(a[i]==f)
{
printf("Element %d found at %d",f,(i+1));
g=1;
}}
if(g==0)
printf("The element %d not found",f);
}


