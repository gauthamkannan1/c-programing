#include <stdio.h>
void main()
{
int a1[50],a2[50],a[50];
int m,n,i,j,k=0;
printf("Enter the size of the first array");
scanf("%d",&m);
printf("Enter the sorted array\n");
for(i=0;i<m;i++)
{
printf("Enter element\n");
scanf("%d",&a1[i]);
}
printf("Enter the size of the second array");
scanf("%d",&n);
printf("Enter the sorted array\n");
for(i=0;i<n;i++)
{
printf("Enter element\n");
scanf("%d",&a2[i]);
}
i=0;j=0;
while(i<m&&j<n)
{
if(a1[i]<a2[j])
{
a[k]=a1[i];
i++;
}
else
{
a[k]=a2[j];
j++;
}
k++;
}
if(i>=m)
{
while(j<n)
{
a[k]=a2[j];
j++;
k++;
}}
if(j>=n)
{
while(i<m)
{
a[k]=a1[i];
i++;
k++;
}}
printf("The merged array is:\n");
for(i=0;i<k;i++)
{
printf("%d \t",a[i]);
}
}
