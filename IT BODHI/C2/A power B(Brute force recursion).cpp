#include<bits/stdc++.h>
using namespace std;
int ApowerB(int , int);
int main(){
    cout<<"Enter base:"<<endl;
    int base;
    cin>>base;
    cout<<"Enter power:"<<endl;
    int power,ans;
    cin>>power;
    ans = ApowerB(base,power);
    cout<<"Answer is:"<<ans<<endl;

}
int ApowerB(int b,int p){
    if(p == 0){
        return 1;
    }
    else if(p == 1){
        return b;
    }
    else{
        return b*ApowerB(b,p-1);
    }
}
