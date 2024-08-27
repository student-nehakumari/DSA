#include<bits/stdc++.h>
using namespace std;
template<typename T>
class node
{
    public:
    T data;
    node<T> *next;      //address(node type)
    node(T data)
    {
        this -> data = data;
        next = NULL;
    }
};
template<typename T>
class Stack
{
    node<T> *head;
    int size;     //no.of element in stack
    public:
    Stack()
    {
        head=NULL;
        size=0;
    }
    int getsize()
    {
        return size;
    }
    bool isEmpty()
    {
        if(head==NULL)
        return true;
        else
        return false;
        //or, return size==0;
    }
    void push(T element)
    {
        node<T> *newNode=new node<T>(element);
        newNode->next=head;
        head=newNode;
        size++;
    }
    T pop()
    {
        if(isEmpty())
        {
            return 0;
        }
        T ans=head->data;
        node<T> *temp=head;
        head=head->next;
        delete temp;
        size--;
        return ans;
    }
    T top()
    {
        if(isEmpty())
        {
            return 0;
        }
        return head->data;
    }
};
int main()
{
    Stack <char>s;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(104);
    s.push(105);
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.getsize()<<endl;
    cout<<s.isEmpty()<<endl;

}