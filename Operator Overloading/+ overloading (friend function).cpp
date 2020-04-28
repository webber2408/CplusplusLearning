#include<iostream>
using namespace std;

class sum{
   private :
       int x;
       int y;
   public :
     friend sum operator+(sum & , sum &);
       sum(int a , int b)
       {
           x = a;
           y = b;
       }
       sum()
       {
           x = 0 ;
           y = 0;
       }
       void disp()
       {
           cout<<x<<y;
       }
};

sum operator+(sum &a1 , sum &b1)
{
    sum temp;
    temp.x = a1.x + b1.x;
    temp.y = a1.y + b1.y;
    return temp;
}
int main()
{
sum  c1(2,3);
sum c2(1, 5);
sum c3;

c3 = c1 + c2;
c3.disp();
}
