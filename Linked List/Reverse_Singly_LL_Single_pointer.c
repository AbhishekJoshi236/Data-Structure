#include <stdio.h>
#include<stdlib.h>

typedef struct node_info
{
    int data;
    struct node_info *next;
}node;

node* createll (node *head,int value)
{
    node *temp;
    node *newnode=(node*)malloc(sizeof(int));
    newnode->data=value;
    newnode->next=NULL;

    if(head==NULL)
    {
        head=temp=newnode;
    }
    else
    {
        temp->next=newnode;
        temp=newnode;
        
    }
    return(temp);
}

void display (node *head)
{
    node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

node* reverse(node *head)
{
    node *prev_node=NULL;
    node *current_node=head, *next_node=head;

    while(next_node!=NULL)
    {
        next_node=next_node->next;
        current_node->next=prev_node;
        prev_node=current_node;
        current_node=next_node;
    }
    head=prev_node;
    return head;
}

int main()
{
    node *head= NULL;
    node *temp=head;
    
    temp=createll(temp,10);
    head=temp;
    
    temp=createll(temp,20);
    temp=createll(temp,30);
    
    display(head);

    head=reverse(head);
    
    printf("\n After reversing: ");
    display(head);
    return 0;
}
