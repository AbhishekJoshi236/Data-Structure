#include <stdio.h>
#include <stdlib.h>

typedef struct node{

    int data;
    struct node *next;
}node;

node *head=NULL;


//INSERTION AT FRONT
void insertfront()
{
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    
    printf("\nEnter a element: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    
    if(head==NULL)
        head=newnode;
    else
    {
        newnode->next=head;
        head=newnode;
    }
    
}


//INSERTION AT BACK
void insertback()
{
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    
    printf("\nEnter a element: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    
    if(head==NULL)
        head=newnode;
    else
    {
        node* temp=head;
        
        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        
    }
}


//INSERTION AFTER A SPECIFIC POSITION 
void insertspecific()
{
    node *newnode,*temp;
    int count=0,p;
    
    printf("\nEnter position number: ");
    scanf("%d",&p);
    
    temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    
    if(p>count)
        printf("\nINVALID POSITION\n\n");
    else
    {
        int i=1;
        node *t=head;
        
        while(i<p)
        {
            t=t->next;
            i++;
        }
        
        newnode=(node*)malloc(sizeof(node));
        if(newnode==NULL)
        {
            printf("\nMemory not available\n");
            exit (0);
        }
        printf("\nEnter a element: ");
        scanf("%d",&newnode->data);
        
        newnode->next=t->next;
        t->next=newnode;
    }    
}


//DISPLAY 
void display()
{
    node *temp=head;
    
    if(head==NULL)
        printf("\nNOTHING IS LINKED TO THE LIST.\n\n");
    else
    {
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n\n");
    }    
}


int main()
{
    int choice;
    while(1)
    {
        
    printf("\nINSERTION OPERATIONS IN LINKED LIST:- \n1.Insertion at FRONT\n2.Insertion at BACK\n3.Insertion after a specific position\n4.DISPLAY\n5.EXIT\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    
    switch(choice)
    {
        case 1: insertfront();
                break;
        case 2: insertback();
                break;
        case 3: insertspecific();
                break;
        case 4: display();
                break;
        case 5: exit(0);
        
        default: printf("\nINVALID CHOICE\n");
    }
}
    return 0;
}
