#include<bits/stdc++.h>
using namespace std;

class polynomial
{
    int *degCoeff;                 //array of polynomial where degree is index and element is coefficient
    int capacity;
    
    public:
    //default constructor
    polynomial()
    {
        degCoeff=new int[10];
        capacity=10;
        for(int i=0;i<capacity;i++)
        {
            degCoeff[i]=0;
        }
    }
    //copy constructor
    polynomial(polynomial const &p)
    {
        //this->degCoeff=p.data;       //shallow copy
        //deep copy
        this->degCoeff=new int[p.capacity];
        for(int i=0;i<capacity;i++)
        {
            this->degCoeff[i]=p.degCoeff[i];
        }
        this->capacity=p.capacity;
    }


    //copy assignment
    bool operator=(polynomial const &p)
    {
        //this->degCoeff=p.data;       //shallow copy
        //deep copy
        this->degCoeff=new int[p.capacity];
        for(int i=0;i<capacity;i++)
        {
            this->degCoeff[i]=p.degCoeff[i];
        }
        this->capacity=p.capacity;
    }

    //setCoefficient
    void setCoefficient(int degree,int coefficient)
    {
        if(degree>=coefficient)
        {
            int *newDegCoeff=new int[2*capacity];
            for(int i=0;i<capacity;i++)
            {
                newDegCoeff[i]=degCoeff[i];  
            }
            //since new data has only scope upto if block so let the data points newdata and deletes newdata memory
            delete[]degCoeff;
            degCoeff=newDegCoeff;
            capacity*=2;
        }
    }
    

    //add
    polynomial operator+(polynomial const &p2)const
    {
        
        //updating ans in fNew
        polynomial pNew;
        int i=0,j=0;
        while(i<capacity && j<p2.capacity)
        {
            int newcoeff=degCoeff[i]+p2.degCoeff[i];
            pNew.setCoefficient(i,newcoeff);
            i++;
            j++;
        }
        while(i<capacity)
        {
            pNew.setCoefficient(i,degCoeff[i]);
            i++;
        }
        while(j<p2.capacity)
        {
            pNew.setCoefficient(j,p2.degCoeff[i]);
            j++;
        }
        
        return pNew;
    }

    //subtract
    polynomial operator-(polynomial const &p2)const
    {
        
        //updating ans in fNew
        polynomial pNew;
        int i=0,j=0;
        while(i<capacity && j<p2.capacity)
        {
            int newcoeff=degCoeff[i]-p2.degCoeff[i];
            pNew.setCoefficient(i,newcoeff);
            i++;
            j++;
        }
        while(i<capacity)
        {
            pNew.setCoefficient(i,degCoeff[i]);
            i++;
        }
        while(j<p2.capacity)
        {
            pNew.setCoefficient(j,p2.degCoeff[i]);
            j++;
        }
        
        return pNew;
    }
    //print()
    void print()const
    {
        for(int i=0;i<capacity;i++)
        {
            cout<<degCoeff[i]<<" ";
        }
        cout<<endl;
    }

    //multiply
};