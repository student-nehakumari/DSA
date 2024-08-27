#include<bits/stdc++.h>
using namespace std;
#include "dynamicArrayClass.cpp"

int main()
{
    dynamicArray d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);

    d1.print();
    
    /*dynamicArray d2(d1); //copy constructor
    d1.addElementATi(2,90);
    d2.print();
    dynamicArray d3;
    d3=d1;
    d1.addElementATi(0,100);
    d3.print();*/
    //we have done all the changes in d1 but it reflects in d2 and d3 as well 
    //so, its prved that copy constructor or assignment both do shallow copy
    
    //deep copy(copy constructor)
    dynamicArray d2(d1);
    d1.addElementATi(2,90);
    d1.print();
    d2.print();
    //copy assignment
    dynamicArray d3;
    d3=d1;
    d3.print();
}