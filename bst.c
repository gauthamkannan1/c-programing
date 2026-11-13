#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*left;
struct node*right;
};
struct node*createnode(int value)
{
struct node*newnode;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=value;
newnode->left=NULL;
newnode->right=NULL;
return newnode;
}
struct node*insert(struct node*root,int value)
{
if(root==NULL)
return createnode(value);
if(value<root->data)
root->left=insert(root->left,value);
else if(value>root->data)
root->right=insert(root->right,value);
else
printf("duplicate elements are no allowed\n");
return root;
}
void inorder(struct node*root)
{
if(root!=NULL)
{
inorder(root->left);
printf("%d",root->data);
inorder(root->right);
}
}
void preorder(struct node*root)
{
if(root!=NULL)
{
printf("%d",root->data);
preorder(root->left);
preorder(root->right);
}
}
void postorder(struct node*root)
{
if(root!=NULL)
{
postorder(root->left);
postorder(root->right);
printf("%d",root->data);
}
}
struct node*findMin(struct node*root)
{
while(root!=NULL&&root->left!=NULL)
root=root->left;
return root;
}
struct node*deletenode(struct node*root,int value)
{
struct node*temp;
if(root==NULL)
{
printf("Element not found");
return NULL;
}
if(value<root->data)
root->left=deletenode(root->left,value);
else if(value>root->data)
root->right=deletenode(root->right,value);
else
{
if(root->left==NULL&&root->right==NULL)
{
free(root);
return NULL;
}
else if(root->left==NULL)
{
temp=root->right;
free(root);
return temp;
}
else if(root->right==NULL)
{
temp=root->left;
free(root);
return temp;
}
else
{
temp=findMin(root->right);
root->data=temp->data;
root->right=deletenode(root->right,temp->data);
}
}
return root;
}
int main()
{
struct node*root=NULL;
int choice,value;
do
{
printf("\n---------BINARY SEARCH  TREE-----\n");
printf("1.insert\n");
printf("2.inorder traversal\n");
printf("3.preorder traversal\n");
printf("4.postorder traversal\n");
printf("5.delete a node\n");
printf("6.Exit\n");
printf("enter a choice");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("enter value to insert:");
       scanf("%d",&value);
       root=insert(root,value);
       break;
case 2:printf("inorder traversal");
       inorder(root);
       printf("\n");
       break;
case 3:printf("preorder traversal");
       preorder(root);
       printf("\n");
       break;
case 4:printf("postorder traversal");
       postorder(root);
       printf("\n");
       break;
case 5:printf("enter value to be deleted");
       scanf("%d",&value);
       root=deletenode(root,value);
       break;
case 6:printf("exiting program....\n");
       break;
default:printf("invalid choice!\n");
}
}while(choice!=6);
return 0;
}
       
                            
