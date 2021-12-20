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


tree* successor(tree *root)
{
    root=root->right;
    while(root->left != NULL)
    {
        root=root->left;
    }
    return root;
}


tree * delete_node(tree *root,int key)
{
    tree *suc;

    if(root==NULL)
        return NULL;        

    if(key< root->data)
    {
        root->left=delete_node(root->left,key);
    }    
    else if(key> root->data)
    {
        root->right=delete_node(root->right,key);
    }
    else
    {
        if(root->right==NULL)
        {
           tree* temp =root->left;
            printf("\nNEW VALUE AT DELETED POSITION: %d",temp->data);
            free (root);
            return temp;
        }
        if(root->left==NULL)
        {
            tree * temp =root->right;
            printf("\nNEW VALUE AT DELETED POSITION: %d",temp->data);
            free(root);
            return temp; 
        }    
        suc=successor(root);
        root->data=suc->data;
        printf("\nNEW VALUE AT DELETED POSITION: %d",root->data);
        root->right=delete_node(root->right,suc->data);
    }

    return root;
}


int main()
{
    int choice,item;
    tree *root=NULL;
    printf("\nOperations in BST: ----");
    while(1)
    {
        printf("\n1.INSERT\n2.DISPLAY\n3.DELETE\n4.EXIT\nEnter Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter data: ");
                    scanf("%d",&item);
                    root=insertnode(root,item);
                    break;
        
            case 2: printf("\nDISPLAYING.......\n");
                    inorderdisplay(root);
                    printf("\n");
                    break;

            case 3: printf("Enter the data of node which u want to delete:   ");
                    scanf("%d",&item);
                    root=delete_node(root,item);
                    break;

            case 4: exit(0);
            default: printf("\nINVALID CHOICE\n");
        }
    }
    return 0;
}
