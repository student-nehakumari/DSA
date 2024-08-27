#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node *next;      //address(node type)
    node(int data)
    {
        this -> data = data;
        next = NULL;
    }
};