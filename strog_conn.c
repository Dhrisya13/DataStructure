#include<stdio.h>
#include<stdlib.h>
#define size 10
struct node  //to represent vertex and edge
{
int data;
int status;
struct node *next,*point;
};
int stk[size],sp=0;
//function to store a vertex
struct node *addvertex(struct node *g,int n)
{
struct node *t=(struct node*)malloc(sizeof(struct node));
t->data=n;
t->point=0;
t->status=0;
t->next=g;
g=t;
return g;
}
//function to find vertex node of a vertex
struct node *find(struct node *g,int n)
{
struct node *t=g;
  while(t!=0 && t->data!=n)
      t=t->next;
  return t;
}
//Function to add a edge
void addedge(struct node *g,int u,int v)
{
struct node *v1,*v2,*t;
v1=find(g,u);
v2=find(g,v);
t=(struct node*)malloc(sizeof(struct node));
t->next=v1->point;
v1->point=t;
t->point=v2;
return;
}
//function to print a graph
void printgraph(struct node *g)
{
struct node *t1,*t2,*t3;
printf("\nvertex   Edge list\n");
t1=g;
while(t1!=0)
{
printf("\n%d...\t",t1->data);
t2=t1->point;
while(t2!=0)
   {t3=t2->point;
      printf(" %d,",t3->data);
      t2=t2->next;
   }
   t1=t1->next;
}
}
//DFS Visit
void dfs_visit(struct node *u)
{
     struct node *t,*t1;
     u->status=1;  //visit vertex
     //printf("%d,",u->data);
     t=u->point;
   while(t!=0)
     {
     t1=t->point;
   if(t1->status==0)//if not visited
     dfs_visit(t1);
     t=t->next;
     }
stk[++sp]=u->data;  //store the node in a stack
return;
}
//DFS Search
void dfs(struct node *g1)
{
struct node *t=g1;
    while(t!=0)
     {
       t->status=0; //set as not visited
       t=t->next;
     }
     t=g1;
     while(t!=0)
     {
     if(t->status==0)//if not visited invoke dfs_visit
     dfs_visit(t);
     t=t->next;
}
}
//DFS Visit 1
void dfs_visit1(struct node *u)
{
     struct node *t,*t1;
     u->status=1;  //visit vertex
     printf("%d,",u->data);
     t=u->point;
   while(t!=0)
     {
     t1=t->point;
   if(t1->status==0)//if not visited
     dfs_visit1(t1);
     t=t->next;
     }
     }
//DFS Search 1
void dfs1(struct node *g1)
{
struct node *t=g1;
    while(t!=0)
     {
       t->status=0; //set as not visited
       t=t->next;
     }
     while(sp!=0)
     {
     t=find(g1,stk[sp--]);
     if(t->status==0)//if not visited invoke dfs_visit1
     {dfs_visit1(t);
     printf("\n");
}
}
}
//To find transpose of a graph
struct node * graph_transpose(struct node *g)
{
struct node *gt=0,*t=g,*t1,*t2;
while(t!=0)//copy the vertex list
{
gt=addvertex(gt,t->data);
 t=t->next;
 }
t=g;
while(t!=0)//finding edge and reversing
  {
  t1=t->point;
   while(t1!=0)//
   {
   t2=t1->point;
   addedge(gt,t2->data,t->data);
     t1=t1->next;
     }
     t=t->next;
     }
     return gt;
     }
//mainfunction to demonstrate graph search and topological sort
int main ()
{
struct node *g=0,*gt=0,*t;//to store graph
g=addvertex (g,8);
g=addvertex (g,7);
g=addvertex (g,6);
g=addvertex (g,5);
g=addvertex (g,4);
g=addvertex (g,3);
g=addvertex (g,2);
g=addvertex (g,1);
g=addvertex (g,0);

addedge(g,0,1);
addedge(g,1,2);
addedge(g,2,3);
addedge(g,3,0);
addedge(g,2,4);
addedge(g,4,5);
addedge(g,5,6);
addedge(g,6,4);
addedge(g,7,6);
addedge(g,7,8);
dfs(find(g,0));
printf("The graph is:\n");
printgraph(g);

gt=graph_transpose(g);
printf("\n Transpose of the graph:\n");
printgraph(gt);
printf("\n strongly connected components:\n");
dfs1(gt);

return 0;
}
