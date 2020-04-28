#include<bits/stdc++.h>
using namespace std;
#define MAX 100
long long int results[MAX];
long long int ApowerB(int , int);
int main(){
    cout<<"Enter base:"<<endl;
    int base;
    cin>>base;
    cout<<"Enter power:"<<endl;
    int power;
    long long int ans;
    cin>>power;
    //int results[power];
    for(int i=0;i<=power;i++){
        results[i] = -1;
    }
    results[0] = 1;
    results[1] = base;
    ans = ApowerB(base,power);
    cout<<"Answer is:"<<ans<<endl;
    for(int i=0;i<=power;i++){
        cout<<results[i]<<endl;
    }

}
long long int ApowerB(int b,int p){
    cout<<"p"<<results[p]<<endl;

    if(p < 0){
        cout<<"1"<<endl;
        return -1;
    }
    if(results[p]>0){
        cout<<"12"<<endl;
        cout<<"here"<<endl;
        return results[p];
    }
    else{
        cout<<"13"<<endl;
        if(p%2 == 0){

            results[p] = ApowerB(b,p/2)*ApowerB(b,p/2);
            return results[p];
        }else{
            results[p] =  b*ApowerB(b,p/2)*ApowerB(b,p/2);
            return results[p];
        }
    }
}
