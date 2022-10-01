#include<bits/stdc++.h>
using namespace std;

void print(int a[],int n)
{
    cout<<"Printing: ";
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void heapify(int arr[],int n,int i)
{
    int current = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <=n && arr[current] < arr[left])
        current = left;
    if(right <=n && arr[current] < arr[right])
        current = right;

    if(current!=i){
        swap(arr[current],arr[i]);
        heapify(arr,n,current);
    }

}
void buildHeap(int arr[],int n)
{
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
}

void heapSort(int arr[],int n)
{
    int size = n;

    while(size>1){

        swap(arr[1],arr[size]);
        size--;

        heapify(arr,size,1);
    }
}
int main()
{
    int arr[6] = {-1,4,7,2,1,5};
    int n=5;

    print(arr,n);

    buildHeap(arr,n);   //maxheap
    print(arr,n);
    
    heapSort(arr,n);

    print(arr,n);

    return 0;

}
