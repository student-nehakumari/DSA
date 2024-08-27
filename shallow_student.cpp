#include<bits/stdc++.h>
using namespace std;
#include "shallow&deep_copy.cpp"
int main()
{
    char name[]="abcd";
    student s1(20,name);
    s1.display();
    //copy constructor
    student s2(s1);
    //copy constructor do shallow copy
    s2.name[0]='x';
    s1.display();
    s2.display();


    /*name[3]='e';
    student s2(25,name);
    s2.display();
    s1.display();*/

}