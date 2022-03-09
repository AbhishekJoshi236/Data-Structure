/*
Explanation:

given array is:
3 1 4 5 2

sorting process:            //find minimum element,then swap it.
1 3 4 5 2 
1 2 4 5 3 
1 2 3 5 4
1 2 3 4 5


T.C-> O(n square)       because of nested loops.
S.C-> O(1)
*/


#include<iostream>
using namespace std;

void swap(int *p1,int *p2)
{
    int c=*p1;
    *p1=*p2;
    *p2=c;
}


void sorting (int a[],int n)
{
    for(int i=0; i<n-1; i++)
    {
        int min_index=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min_index])
            {
                min_index=j;
            }
        }

        swap(a[i],a[min_index]);
    }
    

}

int main()
{
    int a[5]={3,4,2,1,5};

    for(int i=0;i<5;i++)
        cout<<a[i]<<" ";

    cout<<endl;
    sorting(a,5);

    for(int i=0;i<5;i++)
        cout<<a[i]<<" ";
}