#include<iostream>
using namespace std;

class space{
   private :
       int x;
       int y;
       int z;
   public:
       space(){
       x=0 ;
       y=0 ;
       z=0;
       }
      void show()
       {
              cout<<x<<y<<z<<endl;
       }
    space(int a, int b , int c )
    {
        x =  a;
        y = b;
        z = c;

    }
     void operator-()
     {
         x = -x;
         y = -y;
         z = -z;
     }
};

int main()
{
space s(1 , 2 , 3);
s.show();
 -s;
 s.show();

}
