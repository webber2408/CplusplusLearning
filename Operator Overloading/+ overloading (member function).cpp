#include<iostream>
using namespace std;

class sum{
   private :
       int x;
       int y;
   public :
       sum operator+(sum &obj)
       {
           obj.x = x + obj.x;
           obj.y = y + obj.y;

           return obj;
       }
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

int main()
{
sum  c1(2,3);
sum c2(1, 5);
sum c3;

c3 = c1 + c2;
c3.disp();
}
