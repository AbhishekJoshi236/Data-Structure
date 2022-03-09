#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print (vector<int> v)
{
    for(auto x:v)
        cout<<x<<" ";
    cout<<endl;
}
int sorting_algorithm(vector<int>& v,int lb,int up)
{
    int pivot=v[lb];                        //1st element as pivot
    int start=lb, end= up;
    while(start < end)
    {
        while(v[start]<=pivot)
            start++;
        while(v[end]> pivot)
            end--;
        
        //after two while , start and end are in position to swap
        if(start<end)
            swap(v[start],v[end]);
    }

    //swapping end with pivot.
    swap (v[lb],v[end]);

    return end;
}

void Quick_Sort(vector<int> &v,int lb,int up)
{
    
    if(lb < up )
    {
        int index = sorting_algorithm(v,lb,up);
        Quick_Sort(v,lb,index-1);           //applying sorting in left
        Quick_Sort(v,index+1,up);           //applying sorting in right
    }
}
int main()
{
    cout<<"Before: ";
    vector<int> v={1,56,-34,9,8,2,10,-1};
    print(v);

    int lb=0, up=v.size()-1;
    Quick_Sort(v,lb,up);
    cout<<"after: ";
    print(v);

return 0;
}