#include<iostream>
using namespace std ;


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
    int  operator==(sample &obj)
    {
        if(x == obj.x && y == obj.y)
        {
            return 1;

        }
        else {
            return 0;
        }
    }
    void disp()
    {
        cout<<x<<y;
    }
  };

int main(){
  sample s(1 ,  2 );
  sample s1(1 , 2);

  if(s1 == s)
  {
      cout<<"Equal";
  }
  else{
    cout<<"Not equal";
  }

  s1.disp();
}
