#include<stdio.h>
#define n 3
int f=-1,r=-1;
int a[n];

void enqueuefront()
{
    int item;
    if((f==0 && r==n-1) || (f==r+1))
        printf("\nQueue is Full.\n");
    else if(f==-1 || r==-1)
    {
        f=r=0;
        printf("Enter element: ");
        scanf("%d",&item);
        a[f]=item;
    }
    else if(f==0)
    {
        f=n-1;
         printf("Enter element: ");
        scanf("%d",&item);
        a[f]=item;
    }
    else
    {
        --f;
         printf("Enter element: ");
        scanf("%d",&item);
        a[f]=item;
    }
}      


void enqueuerear()
{
    int item;
    if((f==0 && r==n-1) || (f==r+1))
        printf("\nQueue is Full.\n");
    else if(f==-1 || r==-1)
    {
        f=r=0;
        printf("\nEnter element: ");
        scanf("%d",&item);
        a[r]=item;
    }
    else if(r==n-1)
    {
        r=0;
        printf("\nEnter element: ");
        scanf("%d",&item);
        a[r]=item;
    }
    else
    {
        r++;
        printf("\nEnter element: ");
        scanf("%d",&item);
        a[r]=item;
    }
}


void dequeuefront()
{
    if(f==-1 && r==-1)
        printf("\nQueue is EMPTY.\n");
    else if(f==r)
    {
        printf("\nDEQUEUED element is: %d\n",a[f]);
        f=r=-1;
    }
    else if(f==n-1)
    {
        printf("\nDEQUEUED element is: %d\n",a[f]);
        f=0;
    }
    else
    {
        printf("\nDEQUEUED element is: %d\n",a[f]);
        f++;
    }
}

void dequeuerear()
{
    if(f==-1 && r==-1)
        printf("\nQueue is EMPTY.\n");
    else if(f==r)
    {
        printf("\nDEQUEUED element is: %d\n",a[r]);
        f=r=-1;
    }
    else if(r==0)
    {
        printf("\nDEQUEUED element is: %d\n",a[r]);
        r=n-1;
    }
    else
    {
        printf("\nDEQUEUED element is: %d\n",a[r]);
        --r;
    }
}
void display ()
{
    if(f==-1 && r==-1)
        printf("\nQueue is EMPTY.\n");
    
    else
    {
        int c=f;
        while(c!=r)
        {
            printf("%d ",a[c]);
            c=(c+1)%n;
        }
        printf("%d",a[r]);
        printf("\n\n");
    }
}



int main()
{
    int choice;
    while(1)
    {
        printf("\n\nOPERATIONS:\n1.Enqueue from front\n2.Enqueue from rear\n3.Dequeue from front\n4.Dequeue from rear\n5.Display\n6.EXIT\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: enqueuefront();
                break;
            case 2: enqueuerear();
                break;    
            case 3: dequeuefront();
                break;
            case 4: dequeuerear();
                break; 
            case 5: display();
                break;
            case 6: return 0;
                break;
        }
    }

}
