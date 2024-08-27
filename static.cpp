#include<bits/stdc++.h>
using namespace std;
class student
{
    //private property
    static int totalStudents; //total no. of students present
    
    //public property
    public:
    int rollno;
    int age;
    //calling constructor to count total no. of students
    student()
    {
        totalStudents++;
    }
    int getRollno()
    {
        return rollno;
    }
    //static function - belong to complete class
    static int getTotalStudents()          //static property
    {
        return totalStudents;
    }
};
int student :: totalStudents=0;           //initialize static data member
