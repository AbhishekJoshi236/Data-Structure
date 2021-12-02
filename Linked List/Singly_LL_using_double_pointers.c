#include <stdio.h>
#include<stdlib.h>

typedef struct node_info
{
    int data;
    struct node_info *next;
}node;

void createll (node **head,int value)
{
    node *temp;
    node *newnode=(node*)malloc(sizeof(int));
    newnode->data=value;
    newnode->next=NULL;

    if(*head==NULL)
        *head=temp=newnode;
    else
    {
        temp->next=newnode;
        temp=newnode;
    }
}

void display (node **head)
{
    node *temp=*head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main()
{
    node *head= NULL;
    createll(&head,10);
    createll(&head,20);
    createll(&head,30);
    display(&head);

    return 0;
}
