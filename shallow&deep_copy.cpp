#include<bits/stdc++.h>
using namespace std;
class student
{
    int age;

    public:
    char *name;
    student(int age,char *name)
    {
        this ->age=age;
        //shallow copy: copying only 0th index
        
        //this ->name=name;
        
        //deep copying: creating new array and copying earlier array into new one
        this -> name= new char[strlen(name)+1]; //+1for \0 char
        //copying earlier array to new one
        strcpy(this -> name,name);
    }
    student(student const &s)
    {
        this -> age = s.age;
        //this ->name=s.name;   //this is shallow copy

        //deep copy
        this -> name=new char[strlen(s.name)+1]; //+1 for'\0'
        strcpy(this -> name, s.name);
    }
    void display()
    {
        cout<<name<<" "<<age<<endl;
    }
};