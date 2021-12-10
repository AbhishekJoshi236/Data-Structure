/*    Insertion is done using double pointer.
      Displaying elements using inorder traversal.    */

#include<stdio.h>
#include<stdlib.h>

typedef struct tree_info
{
    int data;
    struct tree_info *left,*right;
    
}tree;

tree* insert (tree **root,int item)
{
    if((*root)==NULL)
    {
        tree *newnode=(tree*)malloc(sizeof(tree));
        newnode->data=item;
        newnode->left=NULL;
        newnode->right=NULL;
        *root=newnode;
    }
    else
    {
        if(item< ( (*root)->data) )
            insert(&((*root)->left), item);
        else
            insert(&((*root)->right), item);

    }

}

void display (tree *root)
{
    if(root!=NULL)
    {
        display(root->left);
        printf("%d ",root->data);
        display(root->right);
    }
}
int main()
{
    tree *root=NULL;
    insert(&root,100);
    insert(&root,50);
    insert(&root,200);
    insert(&root,70);
    insert(&root,80);
    insert(&root,300);
    display(root);
}
