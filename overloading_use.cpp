#include<bits/stdc++.h>
using namespace std;
#include "oprator_overloading.cpp"
int main()
{
    fraction f1(10,2);
    fraction f2(15,4);
 
    fraction f3=f1.add(f2);
    fraction f4=f1+f2;        //operator overloading

    fraction f5=f1*f2;
    
    if(f1==f2)
    {
        cout<<"equal fractions"<<endl;
    }
    else
    cout<<"unequal fractions"<<endl;

    f1.print();
    f2.print();
    f3.print();
    f4.print();
    f5.print();

    //++(++f1);
    fraction f7=++(++f1);
    f1.print();
    f7.print();
    //f1++
    fraction f8=f1++;
    f1.print();
    f8.print();
    //(i++)++  nesting in post increment is not allowed
    f1+=f2;
    f1.print();
    f2.print();

}