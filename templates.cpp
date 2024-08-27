#include<bits/stdc++.h>
using namespace std;
//if we want to form Pair class in which the data elements can vary wih requirements of the user then we can use templates
//Pair double, Pair char etc.
//here T(float,double,int,char) is the temporary variable datatype
template<typename T, typename V>
class Pair
{
    T x;              //int x
    V y;              //double y
                  
    public:
    void setX(T x)     //void set(int x)
    {
        this->x=x;
    }
    T getX()          //int getX()
    {
        return x;
    }
    void setY(V y)     //void set(double y)
    {
        this->y=y;
    }
    V getY()          //double getY()
    {
        return y;
    }
};