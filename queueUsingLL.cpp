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
class Queue
{
    node<T> *head;
    node<T> *tail;
    int size;
    public:
    Queue()
    {
        head=NULL;
        tail=NULL;
        size=0;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size==0;
    }
    //INSERTING AN ELEMENT
    void enqueue(T element)
    {
        node<T> *newNode=new node<T>(element);
        //if queue is empty and inserting 1st node
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
        }
        else
        {
            tail->next=newNode;
            tail=newNode;
        }
        size++;
    }
    T front()
    {
        if(isEmpty())
        {
            return 0;
        }
        return head->data;
    }
    T dequeue()
    {
        if(isEmpty())
        {
            return 0;
        }
        T ans= head->data;
        node<T> *temp=head;
        head=head->next;
        delete temp;
        size--;
        return ans;
    }
};


int main()
{
    Queue<int>q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    cout<<q.front()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    cout<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;
}