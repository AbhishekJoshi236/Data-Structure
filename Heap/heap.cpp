#include<bits/stdc++.h>
using namespace std;
//0th index is not bee used of array
class heap{

    public: 
        int a[100];
        int size;
        heap(){
            size=0;
        }

        //max heap insertion.
        void insert(int val){       //O(logn)
            size++;
            int index = size;
            a[index] = val;

            while(index > 1)
            {
                int parent = index/2;

                if(a[parent] < a[index]){
                    swap(a[parent],a[index]);
                    index = parent;
                }
                else
                    return;     //imp to write else (return condn).
            }
        }

        //delete function always  deletes the root element.
        void deletefromheap(){          //O(logn)
            a[1]=a[size];
            size--;

            int i=1;
            while(i<size){

                int leftchild = 2*i;
                int rightchild = 2*i+1;

                if(leftchild<size && a[leftchild] > a[i]){
                    swap(a[leftchild] , a[i]);
                    i=leftchild;  
                }
                else if(rightchild<size && a[rightchild] > a[i]){
                    swap(a[rightchild] , a[i]);
                    i=rightchild;  
                }
                else 
                    return ;        //imp to write else (return condn).

            }
        }
        void print(){
            cout<<"Printing: ";
            for(int i=1;i<=size;i++){
                cout<<a[i]<<" ";
            }cout<<endl;
        }    
};
int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    h.deletefromheap();

    h.print();

    return 0;
}