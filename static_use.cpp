#include<bits/stdc++.h>
using namespace std;
#include "static.cpp"

int main()
{
    student s1;
    student s2;
    student s3;
    student s4,s5,s6;
    cout<<s1.rollno<<" "<<s1.age<<endl;
    //unethical-we should no do it
    //cout<<s1.totalStudents<<endl; 
    //s1.totalStudents=34;
    //student s2;
    //cout<<s2.totalStudents<<endl; 

    //private property so cant access 
    //cout<<student :: totalStudents<<endl;   //6 students
    
    cout<<student :: getTotalStudents()<<endl;
}