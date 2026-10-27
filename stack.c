#include <stdio.h>
int s[50];
int ele,top=-1,size,ch,i;
void push()
{
if(top==size-1)
{
    printf("stack is full/overflow");
}
else
{     
    printf("enter the number to be inserted");
    scanf("%d",&ele);
    top++;
    s[top]=ele;
    printf("element is pushed successfully");
}
}
void pop()
{
if(top==-1)
{
    printf("the stack is empty/underflow");
}
else
{
    printf("deleted element %d",s[top]);
    top--;
}}
void display()
{
if(top==-1)
{
    printf("the stack is empty");
    }
else
{
    printf("stack elements are:\t");
    for(i=top;i>=0;i--)
    {
         printf("%d\n",s[i]);
     }    
}}           
void main()
{
    printf("enter the size of stack");
    scanf("%d",&size);
    printf("Enter elements in the stack");
    for(i=0;i<size;i++)
    {
    scanf("%d",&s[i]);
    top++;
    }
    do
    {
    printf("\n-----Menu-----\n");
    printf("1.push\n");
    printf("2.pop\n");
    printf("3.display\n");
    printf("4.Exit\n");
    printf("enter your choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1: push();
            break;
    case 2: pop();
            break;
    case 3:display();
           break;
    case 4:printf("Existing");
           break;
    default:printf("invalid choice");
    }
    }while(ch!=4);
    }
