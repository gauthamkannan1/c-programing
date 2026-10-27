#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
struct node *head=NULL;
void create(){
struct node *newnode,*temp;
int n,i;
printf("Enter number of nodes: ");
scanf("%d",&n);
for(i=0;i<n;i++){
newnode=(struct node*)malloc(sizeof(struct node));
printf("Enter data: ");
scanf("%d",&newnode->data);
newnode->next=NULL;
if(head==NULL){
head=newnode;
temp=newnode;
}
else{
temp->next=newnode;
temp=newnode;
}
}
}
void insert_begin(){
struct node *newnode;
newnode=(struct node*)malloc(sizeof(struct node));
printf("Enter data: ");
scanf("%d",&newnode->data);
newnode->next=head;
head=newnode;
}
void insert_end(){
struct node *newnode,*temp;
newnode=(struct node*)malloc(sizeof(struct node));
printf("Enter data: ");
scanf("%d",&newnode->data);
newnode->next=NULL;
if(head==NULL){
head=newnode;
return;
}
temp=head;
while(temp->next!=NULL)
temp=temp->next;
temp->next=newnode;
}
void insert_any(){
struct node *newnode,*temp;
int pos,i;
printf("Enter position: ");
scanf("%d",&pos);
if(pos<=0){
printf("Invalid position\n");
return;
}
if(pos==1){
insert_begin();
return;
}
newnode=(struct node*)malloc(sizeof(struct node));
printf("Enter data: ");
scanf("%d",&newnode->data);
temp=head;
for(i=1;i<pos-1 && temp!=NULL;i++)
temp=temp->next;
if(temp==NULL){
printf("Invalid position\n");
free(newnode);
return;
}
newnode->next=temp->next;
temp->next=newnode;
}
void delete_begin(){
struct node *temp;
if(head==NULL){
printf("List is empty\n");
return;
}
temp=head;
head=head->next;
free(temp);
}
void delete_end(){
struct node *temp,*prev;
if(head==NULL){
printf("List is empty\n");
return;
}
if(head->next==NULL){
free(head);
head=NULL;
return;
}
temp=head;
while(temp->next!=NULL){
prev=temp;
temp=temp->next;
}
prev->next=NULL;
free(temp);
}
void delete_any(){
struct node *temp,*prev;
int pos,i;
if(head==NULL){
printf("List is empty\n");
return;
}
printf("Enter position: ");
scanf("%d",&pos);
if(pos<=0){
printf("Invalid position\n");
return;
}
if(pos==1){
delete_begin();
return;
}
temp=head;
for(i=1;i<pos && temp!=NULL;i++){
prev=temp;
temp=temp->next;
}
if(temp==NULL){
printf("Invalid position\n");
return;
}
prev->next=temp->next;
free(temp);
}
void display(){
struct node *temp;
if(head==NULL){
printf("List is empty\n");
return;
}
temp=head;
while(temp!=NULL){
printf("%d ",temp->data);
temp=temp->next;
}
printf("\n");
}
int main(){
int choice;
create();
printf("\nLinked List: ");
display();
while(1){
printf("\n1. Insert at beginning\n");
printf("2. Insert at end\n");
printf("3. Insert at any position\n");
printf("4. Delete from beginning\n");
printf("5. Delete from end\n");
printf("6. Delete from any position\n");
printf("7. Display\n");
printf("8. Exit\n");
printf("Enter choice: ");
scanf("%d",&choice);
switch(choice){
case 1:
insert_begin();
break;
case 2:
insert_end();
break;
case 3:
insert_any();
break;
case 4:
delete_begin();
break;
case 5:
delete_end();
break;
case 6:
delete_any();
break;
case 7:
display();
break;
case 8:
exit(0);
default:
printf("Invalid choice\n");
}
}
return 0;
}
