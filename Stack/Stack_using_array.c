#include<stdio.h>
int top=-1;
void push (int a[],int n)
{
	int item;
	if(top==(n-1)){
	printf("Stack is full\n\n\n");
	
	}
	else
	{
	printf("Enter item: ");
	scanf("%d",&item);
	++top;
	a[top]=item;
	}
}

void pop(int a[],int n)
{	
	if(top==-1)
	printf("Stack is empty.\n\n\n");
	else
	{
	printf("Poppped item is: %d\n",a[top]);
	--top;	
	}
	
}

void peek(int a[],int n)
{
	if(top==-1)
    	printf("Stack is empty.\n\n\n");
	else
	printf("Top most element is: %d\n",a[top]);
}

void display (int a[],int n)
{
    if(top==-1)
    	printf("Stack is empty.\n\n\n");
	else
	{
	    int c=top;
	    while(c!=(-1))
	    {
	        printf("%d\n",a[c]);
	        c--;
	    }
	}
}
int main()
{

int n;
printf("Enter size of stack: ");
scanf("%d",&n);

int a[n];

while(1)
{
	int choice;
	printf("MENU: \n");
	printf("1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT\nEnter your choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1: push(a,n);
		break;
	case 2: pop(a,n);
		break;
	case 3: peek(a,n);
		break;
	case 4: display(a,n);
		break;
	case 5: return 0;
	default: printf("INVALID CHOICE\n");
	}
}

	return 0;
}



