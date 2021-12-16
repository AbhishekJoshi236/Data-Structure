#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);

    int a[n];
    printf("Enter elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    

    for(int i=0;i<(n-1);i++)                    //number of phases are 1 less than n
    {
        int flag=0;                             // to check weather the swaping is done or not , if not then terminate the program
        for(int j=0;j<(n-1-i);j++)              //for swapping
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=1;
            }
        }

        if(flag==0)
            break;
    }

    for(int i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}
