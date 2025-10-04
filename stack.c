#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*next;
};
void main()
{
struct node*start=(struct node*)0;
struct node*push(struct node*,int);
struct node*pop(struct node*);
void display(struct node*);
int search(struct node*,int),opt,item,ans;
while(1)
{
printf("\n1.Insert \n2.Delete \n3.Display \n4.Search \n5.Exit\n");
printf("Your option:");
scanf("%d",&opt);
switch(opt)
{
case 1:printf("item to insert:");
       scanf("%d",&item);
       start=push(start,item);
       break;
case 2:start=pop(start);
       break;
case 3:display(start);
       break;
case 4:printf("item to search:");
       scanf("%d",&item);
       ans=search(start,item);
       if(ans==1)
         printf("item found...");
       else
         printf("item not found...");
       break;
case 5:exit(0);
}
}
}
//function to push
struct node* push(struct node* list,int data)
{
struct node* t;
t=(struct node*)malloc(sizeof(struct node));
t->data=data;//to fill data
t->next=list;//attach at beginning
list=t;
return list;
}
//function to pop
struct node* pop(struct node * list)
{
struct node* t=list;
if(list!=(struct node*)0)
{
printf("deleted data is:%d\n",list->data);
list=list->next;
free(t);
}
else
  printf("list is null\n");
  return list;
}
//function to display
void display(struct node* list)
{
while(list!=(struct node * )0)
{
printf("%d\n",list->data);
list=list->next;
}
return;
}
//function to search
int search(struct node * list,int item)
{
while(list !=(struct node*)0 && item != list->data)
list=list->next;
if(list==(struct node * )0)
return 0;
else
return 1;
}
