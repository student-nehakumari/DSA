#include<vector>
using namespace std;
template<typename T>
class treeNode
{
    public:
    T data;
    vector<treeNode*>children;
    //vector<treeNode<T>*>children; //can or cannot write <T> since child is alike parent

    //costructor
    treeNode(T data)
    {
        this->data=data;
    }
    ~treeNode()
    {
        for(int i=0;i<children.size();i++)
        {
            delete children[i];
        }
    }
};