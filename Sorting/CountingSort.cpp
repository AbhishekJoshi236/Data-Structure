#include <iostream>
using namespace std;

void print(int a[],int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}

int main()
{
    int n=10;
    int a[n]={0,7,2,0,5,6,3,4,2,6};
    int b[n];
    print(a,n);


    int key=a[0];
    for(int i=0;i<n;i++)
    {
        if(a[i]>key)
            key=a[i];
    }

    int count[key+1]={0};

    for(int i=0;i<n;i++)
    {
        ++count[a[i]];
    }

    for(int i=1;i<n;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    
    for(int i=n-1;i>=0;i--)
    {
        b[--count[a[i]]]=a[i];
    }

    print(b,n);

    return 0;
}
