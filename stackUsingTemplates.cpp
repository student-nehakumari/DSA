#include<bits/stdc++.h>
using namespace std;
template<typename T>
class stackUsingArray_templates
{
    T *data;           //any type data
    int nextIndex;
    int capacity;
    public:
    stackUsingArray_templates()     //constructor
    {
        data=new T[5];
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
    void push(T element)
    {
        //to check whether stack is full or not
        if(nextIndex==capacity)
        {
            T *newData=new T [2*capacity];
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
    T pop()
    {
        if(isEmpty())
        {
            cout<<"stack is empty"<<endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }
    T top()
    {
        if(isEmpty())
        {
            cout<<"stack is empty"<<endl;
            return 0;
        }
        return data[nextIndex-1];
    }
};
int main()
{
    stackUsingArray_templates <char>s;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(104);
    s.push(105);
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;

}