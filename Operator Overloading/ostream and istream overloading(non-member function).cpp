#include<iostream>
#include<stdlib.h>
using namespace std;

class sample{
   private :
       int x ;
       int y ;
   public :
    friend ostream & operator<<(ostream & , sample &);
    friend istream & operator>>(istream & , sample &);
};
ostream &operator<<(ostream &output , sample &s)
{
    output<<s.x<<endl<<s.y;
    return output;
}

istream &operator>>(istream &input , sample &s)
{
    input>>s.x;
    input>>s.y;

    return input;
}

int main(){
   sample s1;

   cout<<"Enter value of x and y "<<endl;
   cin>>s1;
   cout<<"Values entered  are :"<<endl;
   cout<<s1;
}
