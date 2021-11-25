#include <stdio.h>
#include <stdlib.h>

typedef struct node_info
{
    int data;
    struct node_info *next;
}node;

node *front=NULL;
node *rear=NULL;

void enqueue ()
{
    node *newnode,*temp;

    newnode=(node*)malloc(sizeof(int));
    printf("\nEnter data:  ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;

    if(front==NULL && rear==NULL)
        front=rear=newnode;
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
    

}


void dequeue()
{
    if(front==NULL && rear==NULL)
        printf("Queue is EMPTY (Nothing to Dequeue)\n\n");
    else
    {
        printf("\nDequeued element is:  %d\n",front->data);
        node *temp=front;
        front=front->next;
        free(temp);
    }
    if(front==NULL)
        rear=NULL;
}


void display()
{
    
    if(front==NULL && rear==NULL)
        printf("Queue is EMPTY(Nothing to Display)\n\n");
    else
    {
        printf("\nDisplaying....\n");
        node *temp=front;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }

        printf("\n");
    }
}


int main()
{
    int choice;

    while(1)
    {
        printf("\nQueue Operations:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n\nEnter your choice:  ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
        }

    }
    return 0;
}
