#include<bits/stdc++.h>
using namespace std;

class Shape{
    protected:
        int width;
        int length;

    public:
        virtual void getArea() = 0;
        void setWidth(int w){
            width = w;
        }
        void setLength(int l){
            length = l;
        }
};

class Square: public Shape{
    public:
        void getArea(){
            cout<<(width*length)<<endl;
        }
};

class Triangle: public Shape{
    public:
        void getArea(){
            cout<<((width * length) / 2)<<endl;
        }
};

int main(){

    Square sq;
    sq.setLength(4);
    sq.setWidth(4);
    sq.getArea();

    Triangle t;
    t.setLength(10);
    t.setWidth(5);
    t.getArea();

    return 0;
}
/*
Output

16
25
*/