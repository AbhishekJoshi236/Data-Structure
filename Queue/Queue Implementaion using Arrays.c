#include<stdio.h>
int f=-1,r=-1;

void enqueue(int a[],int n)
{
    int item;
    if(r==(n-1))
        printf("\n---QUEUE IF FULL (Can't Enqueue)---\n\n");
    else if(f==-1 && r==-1)
    {
        ++f;
        ++r;
        printf("Enter item to ENQUEUE: ");
        scanf("%d",&item);
        printf("\n");
        a[r]=item;
    }
    else
    {
        ++r;
        printf("Enter item to ENQUEUE: ");
        scanf("%d",&item);
        printf("\n");
        a[r]=item;
    }
}


void dequeue(int a[])
{
    if(f==-1 && r==-1)
        printf("\n---QUEUE IS EMPTY (Can't Dequeue)---\n\n");
    else if(f==r)
    {
        printf("\nDEQUEUED item is: %d\n\n",a[f]);
        f=r=-1;
    }
    else
    {
        printf("\nDEQUEUED item is: %d\n\n",a[f]);
        f++;
    }
}


void front(int a[])
{
    if(f==-1 && r==-1)
        printf("\n---QUEUE IS EMPTY (Can't display the front most element.)---\n\n");
    else
    {
        printf("\nFRONT MOST is: %d\n\n",a[f]);
    }
}


void display(int a[],int n)
{
    if(f==-1 && r==-1)
        printf("\n---QUEUE IS EMPTY (Can't Display)---\n\n");
    else
    {
        int c=f;
        while(c!=n)
        {
            printf("%d ",a[c]);
            ++c;
        }
        printf("\n\n");
    }
}
int main()
{
    int n,choice;
    printf("Enter size of QUEUE: ");
    scanf("%d",&n);
    printf("\n");
    
    int a[n];

    while(1)
    {
        printf("---QUEUE OPERATIONS---:\n1.ENQUEUE\n2.DEQUEUE\n3.FRONT\n4.DISPLAY\n5.EXIT\n\nEnter your choice: "); 
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: enqueue(a,n);
    		        break;
            case 2: dequeue(a);
		            break;
            case 3: front(a);
		            break;
		        case 4: display(a,n);
		            break;       
            case 5: return(0);
            
            default: printf("\nINVALID CHOICE\n");
        }

    }

return 0;
}
