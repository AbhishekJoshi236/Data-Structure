#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;
    
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root){

    cout<<"\nEnter a data: ";
    int data;
    cin>>data;

    if(data == -1){
        return NULL;
    }

    root = new Node(data);

    cout<<"\nEnter data for inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"\nEnter data for inserting in right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrder(Node* root){

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();

        for(int i=0;i<n;i++){
            auto front = q.front();
            cout<<front->data<<" ";
            q.pop();
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
        cout<<endl;
    }
}
int main(){

    Node* root = NULL;

    root = buildTree(root);
    
    //checking for the tree.
    cout<<"Level Order Traversal: "<<endl;
    levelOrder(root);

    return 0;
}
