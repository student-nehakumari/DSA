#include<iostream>
#include<queue>
#include "treeNode.h"
using namespace std;
//taking input level wise
treeNode<int>* takeInputLevelWise()
{
    int rootData;
    cout<<"enter data"<<endl;
    cin>>rootData;
    treeNode<int>* root=new treeNode<int>(rootData);
    
    queue<treeNode<int>*>pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0)
    {
        treeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();
        cout<<"enter no. of children of"<<front->data<<endl;
        int numChild;
        cin>>numChild;
        for(int i=0;i<numChild;i++)
        {
            int childData;
            cout<<"enter"<<i<<"th child of"<<front->data<<endl;
            cin>>childData;
            treeNode<int>*child= new treeNode<int >(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

//taking depth wise
treeNode<int>* takeInput()
{
    int rootData;
    cout<<"enter data"<<endl;
    cin>>rootData;
    treeNode<int>* root=new treeNode<int>(rootData);
    
    int n;//no, of children
    cout<<"enter no. of children of"<<rootData<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        treeNode<int>*child=takeInput();
        root->children.push_back(child);
    }
    return root;
}
//print level wise

void printLevelWise(treeNode<int>* root) {
    // Write your code here
    queue<treeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        treeNode<int>* front = q.front();
        q.pop();

        // Print the current node's data
        cout << front->data << ":";

        // Print all children of the current node
        for (int i = 0; i < front->children.size(); ++i) {
            cout << front->children[i]->data;
            if (i < front->children.size() - 1) {
                cout << ",";
            }
            // Add child nodes to the queue for further processing
            q.push(front->children[i]);
        }
        cout << endl;
    }
}

//structurally identical or not
bool areIdentical(treeNode<int> *root1, treeNode<int> * root2) {
    // Write your code here
    if (root1 == NULL && root2 == NULL) {
        return true;
    }
    
    // If one root is null and the other is not, trees are not identical
    if (root1 == NULL || root2 == NULL) {
        return false;
    }
    
    // If root data is not equal, trees are not identical
    if (root1->data != root2->data) {
        return false;
    }
    
    // If the number of children is different, trees are not identical
    if (root1->children.size() != root2->children.size()) {
        return false;
    }
    
    // Recursively check all children
    for (int i = 0; i<root1->children.size(); ++i) {
        if (!areIdentical(root1->children[i], root2->children[i])) {
            return false;
        }
    }
    
    return true;
}

int main()
{
    treeNode<int>* root1 = takeInputLevelWise();
    treeNode<int>* root2 = takeInputLevelWise();
    cout << (areIdentical(root1, root2) ? "true" : "false");
}