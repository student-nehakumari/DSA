#include<bits/stdc++.h>
using namespace std;
#include "templates.cpp"
int main()
{
    /*if both the data member(x,y) are of same datatype
    Pair<int>p1;
    p1.setX(10);
    p1.setY(20);

    cout<<p1.getX()<<" "<<p1.getY()<<endl;
    
    Pair<double>p2;
    p2.setX(101.89);
    p2.setY(203.09);
    cout<<p2.getX()<<" "<<p2.getY()<<endl;
    */
    //if both data member (x,y)are of diff type
    /*
    Pair<int,double>p1;
    p1.setX(504.45);
    p1.setY(903.12);
    cout<<p1.getX()<<" "<<p1.getY()<<endl;
    */
   //if we want to forn triplet with the same pair class
   Pair<Pair<int,int>,int>p2;
   p2.setY(10);
   Pair<int,int>p4;
   p4.setX(13);
   p4.setY(18);

   p2.setX(p4);
   cout<<p2.getX().getX()<<" "<<p2.getX().getY()<<" "<<p2.getY()<<endl;
}
