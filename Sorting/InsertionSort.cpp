#include <iostream>
using namespace std;

void insertionSort(int a[],int n)
{
    for(int i=1;i<n;i++)          //assuming first element to be sorted.
    {
        int temp=a[i];
        int j=i-1;
        
            while(a[j]>temp && j>=0)
            {
                a[j+1]=a[j];
                j--;
            }
            
        a[j+1] = temp;
    }
}
int main()
{
    int a[5]={2,4,1,5,3};

    for(int i=0;i<5;i++)
        cout<<a[i]<<" ";
    cout<<endl;

    insertionSort(a,5);

    for(int i=0;i<5;i++)
        cout<<a[i]<<" ";
    
    return 0;
}



