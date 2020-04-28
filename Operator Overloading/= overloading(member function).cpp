#include<iostream>
using namespace std;

class sample{
private :
    int x ;
    int y ;
public :
    sample()
    {
        x = 0;
        y =0 ;
    }
    sample(int a , int b )
    {

        x = a ;
        y =  b ;

    }
    void operator=(sample &obj)
    {
        x = obj.x;
        y = obj.y;
    }
    void disp()
    {
        cout<<x<<y;
    }
  };

int main(){
  sample s(1 ,  2 );
  sample s1;

  s1 = s ;

  s1.disp();
}
