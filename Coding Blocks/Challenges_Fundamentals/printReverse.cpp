#include<iostream>
using namespace std;


int main(){
    int num;
    cin>>num;

    int revNum = 0;
    while(num>0){
        revNum = revNum*10 + num%10;
        num /= 10;
    }

    cout<<revNum<<endl;

    return 0;
}