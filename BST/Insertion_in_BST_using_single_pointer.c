#include<stdio.h>
#include<stdlib.h>

typedef struct tree_info
{
    int data;
    struct tree_info *left,*right;
}tree;

tree* insertnode(tree* root,int item)
{
    if(root==NULL)
    {
        tree* newnode=(tree*)malloc(sizeof(tree));
        newnode->data=item;
        newnode->left=NULL;
        newnode->right=NULL;
        root=newnode;

    }
    else
    {
        if(item < root->data)
            root->left=insertnode(root->left,item);
        else
            root->right=insertnode(root->right,item);
    }
    return root;
} 

void inorderdisplay(tree*root)
{
    if(root!=NULL)
    {
        inorderdisplay(root->left);
        printf("%d ",root->data);
        inorderdisplay(root->right);
    }
}

int main()
{
    int choice,item;
    tree *root=NULL;
    
    while(1)
    {
        printf("\n1.Insert a node\n2.Display\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :
            {
                printf("Enter data: ");
                scanf("%d",&item);
                root=insertnode(root,item);
                break;
            }
            case 2: inorderdisplay(root);
                break;
        }
    }
    return 0;
}
