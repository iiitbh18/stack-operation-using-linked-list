#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
}*top=NULL;
void push(int item);
int pop();
int peek();
int isempty();
void display();
main()
{
    int choice,item;
    while(1)
    {
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.peek\n");
        printf("4.display\n");
        printf("enter your choice");
        scanf("%d",&choice);
        switch(choice)
        {
       case 1:
         printf("enter the item to be pushed");
         scanf("%d",&item);
         push(item);
         break;
       case 2:
        item=pop();
        printf("popped item is");
        break;
       case 3:
        printf("item at the top is %d",peek());
        break;
       case 4:
        display();
        break;
       case 5:
        exit(1);
       default:
        printf("wrong choice");
        }
    }
}
void push(int item)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("list is overflow");
        return;
        }
    temp->info=item;
    temp->link=top;
    top=temp;
}
int pop()
{
    int item;
    struct node *temp;
    if(isempty())
    {
        printf("stack is underflow\n");
        exit(1);
    }
    temp=top;
    item=top->info;
    top=top->link;
    free(temp);
    return item;

}
int isempty()
{
    if(top==NULL)
        return 1;
    else
        return 0;
}
void display()
{
    struct node *p;
    if(isempty())
    {
        printf("list is underflow");
        exit(1);
    }
    printf("stack elements :\n");
    p=top;
    while(p!=NULL)
    {
        printf("%d\n",p->info);
        p=p->link;
    }
    printf("\n\n");

}
int peek()
{
    if(isempty())
    {
        printf("stack underflown\n");
        exit(1);
    }
    return top->info;
}



















