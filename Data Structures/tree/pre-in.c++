#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int search(int inorder[], int start, int end, int curr)
{
    for(int i=start;i<=end;i++)
    {
        if(inorder[i] == curr)
            return i;
        
    }
    return -1;
}

Node* buildTree(int preorder[], int inorder[], int start, int end)
{

    static int idx = 0;
    
    if(start>end)
        return NULL;
    
    int curr = preorder[idx];
    idx++;
    Node* node = new Node(curr);

    if(start == end)
        return node;
    int posi = search(inorder, start, end, curr);

    node->left = buildTree(preorder, inorder, start, posi-1);
    node->right = buildTree(preorder, inorder, posi+1, end);

    return node;

}

void inorderprint(Node* root)
{
    if(root == NULL)
        return;
    inorderprint(root->left);
    cout<<root->data<<" ";
    inorderprint(root->right);
}


int main()
{
    int preorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};

    Node* root = buildTree(preorder, inorder, 0, 4);
    inorderprint(root);
    return 0;
}
