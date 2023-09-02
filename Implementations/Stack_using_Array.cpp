#include<bits/stdc++.h>
using namespace std;
class Stack{
    public: 
        int top;
        int size;
        int *arr;
    
    Stack(int size){
        top = -1;
        this->size = size;
        arr= new int[size];
    }

    void push(int ele){
        if(size - top > 1){  //push only if space is available
            top++;
            arr[top]=ele;
        }
        else{
            cout<<"\nCan't push (OVERFLOW)";
        }
    }
    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"\nCan't pop (UNDERFLOW)";
        }
    }
    void peek(){
        if(top>=0){
            cout<<"\nPeek: "<<arr[top];
        }
        else{
            cout<<"\nCan't peek (UNDERFLOW)";
        }
    }
    void empty(){
        if(top==-1){
            cout<<"\nYES STACK IS EMPTY";
        }
        else{
            cout<<"\nNO STACK IS NOT EMPTY";
        }
    }
};
int main(){

    Stack st(5);
    st.push(40);
    st.push(50);
    st.push(60);
    st.empty();
    st.push(70);
    st.peek();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.empty();
    st.pop();
    st.peek();
    st.empty();

    return 0;
}
