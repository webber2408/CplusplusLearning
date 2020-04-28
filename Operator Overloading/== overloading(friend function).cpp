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
   friend int operator==(sample &s1 , sample &s2);
    void disp()
    {
        cout<<x<<y;
    }
  };

  int operator==(sample &s1 , sample &s2)
  {
      if(s1.x == s2.x && s1.y == s2.y)
      {
          return 1 ;

      }
      else{
        return 0 ;
      }
  }

int main(){
  sample s(1 ,  2 );
  sample s1(1 , 3);

  if(s1 == s)
  {
      cout<<"Equal"<<endl;
  }
  else{
    cout<<"Not equal"<<endl;
  }

  s1.disp();
}
