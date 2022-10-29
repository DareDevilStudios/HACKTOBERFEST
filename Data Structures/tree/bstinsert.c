#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*left,*right;

};


struct node*newnode(int data){
    struct node*n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}


struct node* insert(struct node*node,int data)
{
    if(node==NULL)
     return newnode(data);
    else{
    

        if(data<node->data)
         node->left= insert(node->left,data);
        else if(data>node->data)
        {
            node->right=insert(node->right,data);
        }
    }    
    return node; 
    
}

void preorder(struct node*n){
    if(n==NULL)
    return;
        
         preorder(n->left);
         printf("\t%d",n->data);
        
         preorder(n->right);
     
}
int main()
{
    struct node*root=NULL;
    root=insert(root,5);
    insert(root,3);
    insert(root,2);
    insert(root,4);
    insert(root,7);
    insert(root,6);
    insert(root,8);
   
    preorder(root);
    return 0;


     
    
    
   
}