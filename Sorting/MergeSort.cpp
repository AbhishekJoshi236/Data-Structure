#include<iostream>
using namespace std;

void print(int a[],int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}

void merge(int a[],int l,int mid,int u)
{
    int n1=mid-l+1;
    int n2=u-mid;

    int leftArray[n1],rightArray[n2];

    for(int i=0;i<n1;i++)
    {
        leftArray[i]=a[l+i];
    }
    for(int i=0;i<n2;i++)
    {
        rightArray[i]=a[mid+1+i];
    }

    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(leftArray[i]<=rightArray[j])
        {
            a[k]=leftArray[i];
            i++;
        }
        else
        {
            a[k]=rightArray[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        a[k]=leftArray[i];
        i++;
        k++;
    }

    while(j<n2)
    {
        a[k]=rightArray[j];
        j++;
        k++;
    }
}
void mergeSort(int a[],int l,int u)
{
    if(l<u)
    {
        int mid=(l+u)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,u);
        merge(a,l,mid,u);
    }
}
int main()
{
    int n=8;
    int a[n]={23,65,21,76,46,89,45,32};

    print(a,n);
    mergeSort(a,0,n-1);
    print(a,n);



    return 0;
}
