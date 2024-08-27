#include<bits/stdc++.h>
using namespace std;
#include "binaryTreeNode.h"

/*printing binaryTree node
//normal printing without any details
void printBinaryTree(binaryTreeNode<int>* root)
{
    //base case
    if(root==NULL)
    return;
    cout<<root->data<<endl;
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}
*/
//printing tree in a proper way
void printBinaryTree(binaryTreeNode<int>* root)
{
    //base case
    if(root==NULL)
    return;
    cout<<root->data<<": ";
    if(root->left!=NULL)   //if(root-left)
    cout<<"left-"<<root->left->data<<" ,";

    if(root->right!=NULL)
    cout<<"right-"<<root->right->data;
    
    cout<<endl;

    printBinaryTree(root->left);
    printBinaryTree(root->right);
}

//take input
binaryTreeNode<int>* takeInput()
{
    int rootData;
    cout<<"enter data"<<" ";
    cin>>rootData;
    //let the terminating condition is -1
    if(rootData==-1)
    return NULL;
    binaryTreeNode<int>* root=new binaryTreeNode<int>(rootData);
    binaryTreeNode<int>* leftChild=takeInput();
    binaryTreeNode<int>* rightChild=takeInput();
    root->left=leftChild;
    root->right=rightChild;
    return root;
}

int main()
{
    //manual input
    /*binaryTreeNode<int>* root=new binaryTreeNode<int>(1);
    binaryTreeNode<int>* node1=new binaryTreeNode<int>(4);
    binaryTreeNode<int>* node2=new binaryTreeNode<int>(5);
    root->left=node1;
    root->right=node2;
    printBinaryTree(root);
    */
    //user input
    binaryTreeNode<int>* root=takeInput();
    printBinaryTree(root);
    delete root;
}