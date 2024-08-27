#include<bits/stdc++.h>
using namespace std;
template<typename T>
class QueueUsingArray
{
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;
    public:
    QueueUsingArray(int  s)
    {
        data=new T[s];
        nextIndex=0;
        firstIndex=-1;
        size=0;
        capacity=s;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size==0;
    }
    //insert an element
    void enqueue(T element)
    {
        //check if queue is full in case of static array

        /*if(size==capacity)
        {
            cout<<"queue is full"<<endl;
            return;
        }
        */
       //dynamic array
        if(size==capacity)
        {
            T *newData=new T[2*capacity];
            int j=0;
            for(int i=firstIndex;i<capacity;i++)
            {
                newData[j]=data[i];
                j++;
            }
            for(int i=0;i<firstIndex;i++)
            {
                newData[j]=data[i];
                j++;
            }
            delete[]data;
            data=newData;   
            firstIndex=0;
            nextIndex=capacity;
            capacity=capacity*2;
        }
        //same for both satic and dynamic array
        data[nextIndex]=element;
        nextIndex=(nextIndex+1)%capacity;       //if last index is filled newindex comes to 0
        if(firstIndex==-1)
        {
            firstIndex=0;
        }
        size++;
    }
    //front
    T front()
    {
        if(isEmpty())
        {
            cout<<"queue is empty"<<endl;
            return 0;
        }
        return data[firstIndex];
    }
    //delete an element
    T dequeue()
    {
        if(isEmpty())
        {
            cout<<"queue is empty"<<endl;
            return 0;
        }
        T ans=data[firstIndex];
        firstIndex=(firstIndex+1)%capacity;
        size--;
        if(size==0)
        {
            firstIndex=-1;
            nextIndex=0;
        }
        return ans;
    }
};