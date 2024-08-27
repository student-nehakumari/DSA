#include<bits/stdc++.h>
using namespace std;

class dynamicArray
{
    int *data;
    int nextindex;
    int capacity;             //total size

    public:
    dynamicArray()
    {
        data=new int [5];
        nextindex=0;
        capacity=5;
    }
    //own copy constructor
    dynamicArray(dynamicArray const &d)
    {
        //this->data=d.data;       //shallow copy
        //deep copy
        this->data=new int[d.capacity];
        for(int i=0;i<nextindex;i++)
        {
            this->data[i]=d.data[i];
        }
        this->nextindex=d.nextindex;
        this->capacity=d.capacity;
    }
    //copy assignment operator(operator overloading)
    void operator =(dynamicArray const &d)
    {
        this->data=new int[d.capacity];
        for(int i=0;i<nextindex;i++)
        {
            this->data[i]=d.data[i];
        }
        this->nextindex=d.nextindex;
        this->capacity=d.capacity;
    }
    void add(int element)
    {
        if(nextindex==capacity)
        {
            int *newdata=new int[2*capacity];
            for(int i=0;i<capacity;i++)
            {
                newdata[i]=data[i];  
            }
            //since new data has only scope upto if block so let the data points newdata and deletes newdata memory
            delete[]data;
            data=newdata;
            capacity*=2;
        }
        data[nextindex]=element;
        nextindex++;
    }
    int getData(int i)const
    {
        if(i<nextindex)
        return data[i];
        else
        return -1;
    }
    void addElementATi(int i ,int element)
    {
        //if i<nextindex overwrite the new element, if i==nextindex,put the element at nextindex or else simply return
        if(i<nextindex)
        {
            data[i]=element;
        }
        else if(i==nextindex)
        {
            add(element);         //add element functin called 
        }
        else 
        return;
    }
    void print()const
    {
        for(int i=0;i<nextindex;i++)
        {
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
};

