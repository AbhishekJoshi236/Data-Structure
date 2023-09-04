#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class Stack{
    public:
    Node* top;

    Stack(){
        top = NULL;
    }

    
    void push(int ele){
       Node *temp = new Node (ele);
       temp->next = top;
       top = temp;
    }

    void pop(){

        if(top!=NULL){
            Node* temp = top->next;
            top->next = NULL;
            delete top;
            top = temp;
        }
        else{
            cout<<"\nStack is empty. Can't POP";
        }
    }

    void peek(){
        if(top!=NULL){
            cout<<"\nTOP ELEMENT: "<<top->data;
        }
        else{
            cout<<"\nStack is empty. Can't PEEK";
        }
    }

    void isEmpty(){
        if(top!=NULL){
            cout<<"\nSTACK IS NOT EMPTY";
        }
        else{
            cout<<"\nStack is empty.";
        }
    }
};
int main(){
    /** to know the size of stack we can define a variable which will keep track of size in Stack Constructor**/
    Stack st;

    st.push(47);
    st.push(48);
    st.push(49);
    st.push(45);
    st.peek();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.peek();
    st.push(45);
    st.isEmpty();
    return 0;
}
