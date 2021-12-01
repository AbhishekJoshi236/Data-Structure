/*  IMPLEMENTATION OF STACK USING LINKED LIST  */


#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node* next;
}node;


node *head=NULL;


void push (int value)          //Insersion at first
{
    node *temp;
    temp=(node *)malloc(sizeof(node));
    
    temp->info=value;
    temp->next=NULL;
    
    if(head==NULL)
    {
        head=temp;
    }
    
    else
    {
        temp->next=head;
        head=temp;
    }
}

void display()
{
    if(head==NULL)
        printf("\nStack is empty.\n");
    else
    {
        printf("\nDisplaying elements: ");
        node* temp=head;
        while(temp!=NULL)
        {
            printf("%d ",temp->info);
            temp=temp->next;
        }
        printf("\n");
    
    }
}

void pop()
{
    if(head==NULL)
        printf("\nStack is empty.\n");
    else
    {
        printf("\nPopped value is: %d\n",head->info);
        head=head->next;
        printf("\n");
    }
}
int main()
{
    int value,choice;
   
    while(1){
    printf("\nSTACK OPERATIONS (Using Linked List): \n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n\nEnter your choice: ");
    scanf("%d",&choice);
    
    switch(choice)
    {
        case 1: 
                printf("Enter value: ");
                scanf("%d",&value);
                push(value);
                break;
        case 2: 
                pop();
                break;
        case 3:
                display(); 
                break;
        case 4:
                exit(0);
        default: 
                printf("\nINVALID CHOICE.\n");
    }
    }
    return 0;
}
