#include<bits/stdc++.h>
using namespace std;
class stackUsingArray
{
    int *data;
    int nextIndex;
    int capacity;
    public:
    stackUsingArray()     //constructor
    {
        data=new int[5];
        nextIndex=0;
        capacity=5;
    }

    //find size of stack
    int size()
    {
        return nextIndex;
    }
    //find if stack is empty
    bool isEmpty()
    {
        /*
        if(nextIndex==0)
        return true;
        else
        return false;
        */
       return nextIndex==0;
    }
    //insert or push elements in stack
    void push(int element)
    {
        //to check whether stack is full or not
        if(nextIndex==capacity)
        {
            int *newData=new int[2*capacity];
            for(int i=0;i<capacity;i++)
            {
                newData[i]=data[i];
            }
            capacity*=2;
            delete[]data;
        }
        data[nextIndex]=element;
        nextIndex++;
    }
    //delete or pop element from stack
    int pop()
    {
        if(isEmpty())
        {
            cout<<"stack is empty"<<endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }
    int top()
    {
        if(isEmpty())
        {
            cout<<"stack is empty"<<endl;
            return INT_MIN;
        }
        return data[nextIndex-1];
    }
};