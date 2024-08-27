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

//print depth wise
void printTree(treeNode<int>* root)
{
    //edge case not a base case
    if(root==NULL)
    return;

    cout<<root->data<<":";

    for(int i=0;i<root->children.size();i++)
    {
        //children are printed
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++)
    {
        //printTree function is called
        printTree(root->children[i]);
    }
}

//count no. of nodes
int numOfNodes(treeNode<int>*root)
{
    if(root==NULL)
    return 0;
    int ans=1;      //1 for the root
    for(int i=0;i<root->children.size();i++)
    {
        ans+=numOfNodes(root->children[i]);
    }
    return ans;
}

//print the nodes present at level k or depth of the tree
void printAtLevelK(treeNode<int>*root,int k)
{
    if(root==NULL)
    return;

    if(k==0){
        cout<<root->data<<endl;
        return;
    }
    for(int i=0;i<root->children.size();i++)
    {
        printAtLevelK(root->children[i],k-1);
    }
}
//count no. of leaf nodes
int getLeafNodeCount(treeNode<int>* root) {
    // Write your code here
    if (root->children.size() == 0) {
        return 1;
    }

    int leafCount = 0;
    for (int i = 0; i < root->children.size(); ++i) {
        leafCount += getLeafNodeCount(root->children[i]);
    }

    return leafCount;
}

//print preorder traversal(root->left->right)
void preOrder(treeNode<int>*root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++)
    {
        preOrder(root->children[i]);
    }
}
//print postorder traversal(left->right->root)
void postOrder(treeNode<int>* root)
{
    if(root==NULL)
    return;
    for(int i=0;i<root->children.size();i++)
    {
        postOrder(root->children[i]);
    }
    cout<<root->data<<" ";
}
//to check whether a treee contain element x or not

bool isPresent(treeNode<int>* root, int x) {
    // Write your code here
    if (root->data == x) {
        return true;
    }

    for (int i = 0; i < root->children.size(); ++i) {
        if (isPresent(root->children[i], x)) {
            return true;
        }
    }

    return false;
}
//print the number of nodes which contains data greater than x.
int getNoOfLargeNodeCount(treeNode<int>* root, int x) {
    // Write your code here
    int count = 0;
    if (root->data > x) {
        count = 1;
    }

    for (int i = 0; i < root->children.size(); ++i) {
        count += getNoOfLargeNodeCount(root->children[i], x);
    }

    return count;
}
//find and return the node for which sum of its data and data of all its child nodes is maximum. 
int sumWithChildren(treeNode<int>* node) {
    int sum = node->data;
    for (int i = 0; i < node->children.size(); ++i) {
        sum += node->children[i]->data;
    }
    return sum;
}
treeNode<int>* maxSumNodeHelper(treeNode<int>* root, int& maxSum) {

    int currentSum = sumWithChildren(root);
    treeNode<int>* maxNode = root;
    maxSum = currentSum;

    for (int i = 0; i < root->children.size(); ++i) {
        int childMaxSum = INT_MIN;
        treeNode<int>* childMaxNode = maxSumNodeHelper(root->children[i], childMaxSum);
        if (childMaxSum > maxSum) {
            maxSum = childMaxSum;
            maxNode = childMaxNode;
        }
    }

    return maxNode;
}

treeNode<int>* maxSumNode(treeNode<int>* root) {
    // Write your code here
    int maxSum = INT_MIN;
    return maxSumNodeHelper(root, maxSum);

}


//delete tree since, dynamically allocated

void deleteTree(treeNode<int>* root)
{
    for(int i=0;i<root->children.size();i++)
    {
        deleteTree(root->children[i]);
    }
    delete root;
}
int main()
{
    /*
    treeNode<int>* root=new treeNode<int>(1);
    treeNode<int>* node1=new treeNode<int>(2);
    treeNode<int>* node2=new treeNode<int>(3);
    root->children.push_back(node1);
    root->children.push_back(node2);
    printTree(root);
    */
    //treeNode<int>*root=takeInput();     //depth wise
    treeNode<int>*root=takeInputLevelWise();
    printLevelWise(root);
    //printTree(root);
    cout<<"no. of nodes are:"<<numOfNodes(root)<<endl;
    cout<<"enter the level you want: ";
    int k;
    cin>>k;
    printAtLevelK(root,k);
    cout<<"no. of leaf nodes are:"<<getLeafNodeCount(root)<<endl;
    //preorder traversal
    cout<<"preorder traversal: ";
    preOrder(root);
    //postorder traversal
    cout<<"postorder traversal: ";
    postOrder(root);
    int x;
    cout<<endl<<"enter the no. from which you want to search greater no.: ";
    cin>>x;
    cout<<"the number of nodes which contains data greater than "<<x<<" is "<<getNoOfLargeNodeCount(root,x)<<endl;
    cout<<"enter the node you want to search: ";
    int y;
    cin>>y;
    cout<<y<<" is Present or not :"<<isPresent(root,y)<<endl;
    treeNode<int>* ans = maxSumNode(root);
    if (ans != NULL) {
        cout << ans->data<< " is the node with maximum sum of itself and its childtren";
    }
    
    //to delete tree
    //method 1: post order traversal
    //deleteTree(root);
    //method 2: destructor-------treeNode.h file
    delete root;
    
}
