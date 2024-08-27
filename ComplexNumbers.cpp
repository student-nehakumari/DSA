#include<bits/stdc++.h>
using namespace std;
class ComplexNumbers {
    // Complete this class  
    private:
    int real;
    int imaginary;
    public:
    ComplexNumbers(int real, int imaginary)
    {
        this ->real=real;
        this ->imaginary=imaginary;
    }  
    void print()
    {
        cout<<real<<" + "<<"i"<<imaginary;
    }
    void plus(ComplexNumbers const c2)
    {
        real=real+c2.real;
        imaginary=imaginary+c2.imaginary;
    }
    void multiply(ComplexNumbers const c2)
    {
        int Ansreal=(real*c2.real)+(imaginary*c2.imaginary*-1);
        int Ansimaginary=(real*c2.imaginary)+(imaginary*c2.real);
        real=Ansreal;
        imaginary=Ansimaginary;
    }
};