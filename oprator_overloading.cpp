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

    //note:-all these fractions are not doing changes in this->num or denominator so are "const fractions" so,put const keyword
    //putting the output in new variable
    fraction add(fraction const &f2) const
    {
        int lcm=denominator*f2.denominator;
        int x=lcm/denominator;
        int y=lcm/f2.denominator;
        int AnsNum=(x*numerator)+(y*f2.numerator);
        //updating ans in fNew
        fraction fNew(AnsNum,lcm);
        //lets call simplify function
        fNew.simplify(); 
        return fNew;
    }

    //adding f1 and f2 using "+" operator
    fraction operator+(fraction const &f2) const
    {
        int lcm=denominator*f2.denominator;
        int x=lcm/denominator;
        int y=lcm/f2.denominator;
        int AnsNum=(x*numerator)+(y*f2.numerator);
        //updating ans in fNew
        fraction fNew(AnsNum,lcm);
        //lets call simplify function
        fNew.simplify();
        return fNew;
    }

    void multiply(fraction const &f2)
    {
        numerator=numerator*f2.numerator;
        denominator=denominator*f2.denominator;
        simplify();
    }

    //multiplying by operator
    fraction operator*(fraction const &f2) const
    {
        int num=numerator*f2.numerator;
        int deno=denominator*f2.denominator;
        fraction fNew(num,deno);
        fNew.simplify();
        return fNew;
    }
    //equal to operator
    bool operator==(fraction const &f2) const
    {
        return(numerator==f2.numerator && denominator==f2.denominator);
    }

    //urinary operators(++,--)
    //pre increment
    fraction & operator++()
    {
        numerator=numerator+denominator;
        simplify();
        return *this;
    }
    //post increment
    fraction operator++(int)      //(int)indicates post increment
    {
        fraction fNew(numerator,denominator);
        numerator=numerator+denominator;
        simplify();
        fNew.simplify();
        return fNew;
    }
    //+=operator
    fraction & operator+=(fraction const &f2)
    {
        int lcm=denominator*f2.denominator;
        int x=lcm/denominator;
        int y=lcm/f2.denominator;
        int AnsNum=(x*numerator)+(y*f2.numerator);
        numerator=AnsNum;
        denominator=lcm;
        //lets call simplify function
        simplify(); //or this->simplify();

        return *this;
    }
};