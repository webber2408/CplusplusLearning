#include<bits/stdc++.h>
using namespace std;
int factorial(int);
int main(){
    cout<<"Enter number to find factorial of :"<<endl;
    int num,ans;
    cin>>num;
    ans = factorial(num);
    cout<<"Factorial of "<<num<<" is "<<ans<<endl;

}
int factorial(int n){
    if(n==0 || n==1 ){
        return 1;
    }
    else if(n < 0){
        return -1;
    }
    else{
        return n*factorial(n-1);
    }
}
