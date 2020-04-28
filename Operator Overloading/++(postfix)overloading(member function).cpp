#include<iostream>
using namespace std;

class check
{
private :
    int i = 0;
public :
    check operator++()
    {
        check temp;

        temp.i=i++;
        return temp;
    }
    void disp()
    {
        cout<<i;
    }
};

int main()
{
  check obj1 , obj ;
  obj1=++obj;
  obj1.disp();
  obj.disp();

}

