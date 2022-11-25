#include <bits/stdc++.h>
using namespace std;

int buildTree(int sl,int sr, vector<int>&arr, vector<int>&segTree, int index){
    if(sl==sr){
        segTree[index] = arr[sl];
        return segTree[index];
    }
    
    int mid = (sl+sr)/2;
    segTree[index] = buildTree(sl,mid,arr,segTree,2*index+1) +
                     buildTree(mid+1,sr,arr,segTree,2*index+2);
    return segTree[index];
}

void update (int sl,int sr, int diff, int pos, vector<int>&segTree,int index){
    
    if(pos<sl || pos>sr)    return;
    
    segTree[index]+=diff;
    if(sl==sr)  return;
    
    int mid = (sl+sr)/2;
    update(sl,mid,diff,pos,segTree,index*2+1);
    update(mid+1,sr,diff,pos,segTree,index*2+2);
}

int RangeSum(int sl,int sr,int l,int h,vector<int>&segTree, int index){
    if(h<sl || sr<l)    return 0;
    else if(l<=sl && sr<=h) return segTree[index];
    else{
        int mid = (sl+sr)/2;
        return RangeSum(sl,mid,l,h,segTree,index*2+1) + RangeSum(mid+1,sr,l,h,segTree,index*2+2);
    }
}

void print(vector<int> arr,int n){
    cout<<"Printing: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
        
    }
    cout<<endl;
}

int main()
{
    int n,q;
    cout<<"N: ";
    cin>> n;
    
    vector<int> arr(n,0);
    
    cout<<"Array: ";
    for(int i=0;i<n;i++)    cin>>arr[i];
    cout<<"Q: ";
    cin>>q;
    
    int s=pow(2,ceil(log2(n)+1))-1;
    vector<int> segTree(s,0);
    buildTree(0,n-1,arr,segTree,0);
    print(segTree,s);
    
    while(q--){
        int ch;
        cout<<"Choice: ";
        cin>> ch;
        
        switch(ch){
            case 1: int pos,val;
                cin>>pos>>val;
                update(0,n-1,val-arr[pos],pos,segTree,0);
                arr[pos]=val;
                print(segTree,s);
                break;
                
            case 2: int l,r;
                    cin>>l>>r;
                    cout<<RangeSum(0,n-1,l,r,segTree,0);
                    break;
        }
    }

    return 0;
}
