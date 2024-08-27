#include<bits/stdc++.h>
using namespace std;
class fraction
{
    private:
    int numerator;
    int denominator;
    public:
    fraction(int numerator,int denominator)
    {
        this -> numerator=numerator;
        this -> denominator=denominator;
    }
    //forming getters and setters
    int getNumerator() const     //using const keyword because it is a const function and do no do any changes
    {
        return numerator;
    }
    int getDenominator() const
    {
        return denominator;
    }
    void setNumerator(int n)
    {
        numerator=n;
    }
    void setDenominator(int d)
    {
        denominator=d;
    }

    void print() const
    {
        cout<<this -> numerator<<"/"<<denominator<<endl;
    }
    //to simplify the fraction, find hcf
    void simplify()
    {
        int gcd=1;
        int small=min(numerator,denominator);
        for(int i=1;i<small;i++)
        {
            if(numerator%i==0 && denominator%i==0)
            {
                gcd=i;
            }
        }
        numerator=numerator/gcd;
        denominator=denominator/gcd;
    }
    void add(fraction const &f2)
    {
        int lcm=denominator*f2.denominator;
        int x=lcm/denominator;
        int y=lcm/f2.denominator;
        int AnsNum=(x*numerator)+(y*f2.numerator);
        //updating ans in f1
        numerator=AnsNum;
        denominator=lcm;
        //lets call simplify function
        simplify(); //or this->simplify();
    }
    void multiply(fraction const &f2)
    {
        numerator=numerator*f2.numerator;
        denominator=denominator*f2.denominator;
        simplify();
    }
};