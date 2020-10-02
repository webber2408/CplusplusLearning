#include<iostream>
using namespace std;

int power(int a, int n){
    if(n==1) return a;
    return a*power(a, n-1);
}

int main(){
    int a, n;
    cin>>a>>n;

    int ans = power(a, n);
    
    cout<<ans<<endl;

    return 0;
}