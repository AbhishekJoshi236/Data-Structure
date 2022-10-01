#include<bits/stdc++.h>
using namespace std;

//maxheap is been build here.
void heapify(int arr[],int i,int n){            //O(logn)

    int current = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left<=n && arr[current]<arr[left]){
        current= left;
    }
    if(right<=n && arr[current]<arr[right]){
        current= right;
    }

    if(current!=i){

        swap(arr[current],arr[i]);
        heapify(arr,current,n);
    }

}
int main(){

    int arr[6]={-1,54,53,55,52,50};
    int n=5;

    for(int i=1;i<=n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    //building heap = O(n).
    for(int i=n/2;i>0;i--){
        heapify(arr,i,n);
    }

    for(int i=1;i<=n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}