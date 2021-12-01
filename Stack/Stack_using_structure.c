#include<stdio.h>
#include<stdlib.h>

//STRUCTURE
typedef struct number
{
    int data;
}stack;

//PUSH
void push (stack* a,int *top)
{
    if(*top==9)
        printf("\n\n--STACK IS FULL--\n\n");
    else
    {
    ++(*top);
    printf("\nEnter a number to push: ");
    scanf("%d",&a[*top].data);
    }
}

//POP
void pop (stack a[],int *top)
{
    if(*top==(-1))
        printf("\nSTACK IS EMPTY\n");
    else
    {
    printf("\nPOPPED ITEM IS: %d\n",a[*top].data);
    --(*top);
    }
}

//PEEK
void peek (stack a[],int top)
{
    if(top==-1)
        printf("\nSTACK IS EMPTY\n");
    else
        printf("\nTOP MOST ELEMENT IS: %d\n",a[top].data);
}

//DISPLAY
void display(stack a[],int top)
{
    if(top==-1)
        printf("\nSTACK IS EMPTY\n");
    else
    {
        printf("\nITEMS IN STACK: \n");
        while(top>=0)
        {
            printf("%d ",a[top].data);
            --top;
        }
        printf("\n");
    }
}
int main()
{
    stack arr[10];
    int top=-1,choice;
    
    while(1)
    {
        printf("\nMENU:\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT\nEnter your choice: ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1: push(arr,&top);
                    break;
            case 2: pop(arr,&top);
                    break;
            case 3: peek(arr,top);
                    break;
            case 4: display(arr,top);
                    break;
            case 5: exit(0);
            default: printf("\n\nINVALID CHOICE\n\n");
        }
    }
    return 0;
}
