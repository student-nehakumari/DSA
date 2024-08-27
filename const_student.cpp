#include<bits/stdc++.h>
using namespace std;
class student
{
    public:
    int age;
    const int rollno;
    int &x;       //age reference variable-need to use initialisation list

    student(int r,int age) : rollno(r),age(age),x(this->age)          //initialisation list
    {
        //rollno=r       //cant do this because rollno is const
        
    }
};