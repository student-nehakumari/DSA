#include<bits/stdc++.h>
using namespace std;
#include "fraction_class.cpp"
int main()
{
    fraction f1(10,2);
    fraction f2(15,4);

    //fraction const f3();
    //cout<<f3.getNumerator()<<" "<<f3.getDenominator()<<endl;
    f1.add(f2);
    f1.print();
    f2.print();
    f1.multiply(f2);
    f1.print();
    f2.print();
}