#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    printf("How many elements are there in array? : ");
    scanf("%d",&n);

    int a[n];
    printf("Enter all elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    for(int i=1;i<n;i++)                //loop for unsorted part
    {
        int temp=a[i];
        int j=i-1;

        while(j>=0 && a[j]>temp)        //loop for shifting to the right
        {
            a[j+1]=a[j];
            j--;
        }

        a[j+1]=temp;
    }

    printf("\nDisplaying after sorting:  ");
    for(int i=0;i<n;i++)
        printf("%d  ",a[i]);


    return 0;
}
