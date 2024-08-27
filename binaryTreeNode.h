template<typename T>
class binaryTreeNode
{
    public:
    T data;
    binaryTreeNode *left;
    binaryTreeNode *right;

    binaryTreeNode(T data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
    //destructor for deleting binary tree node
    ~binaryTreeNode()
    {
        delete left;
        delete right;
    }
};