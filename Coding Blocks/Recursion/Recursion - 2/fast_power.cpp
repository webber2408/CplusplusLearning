#include<bits/stdc++.h>
using namespace std;

// tc O(N) sc O(N)
int power(int a, int n){
    if(n==0) return 1;
    return a*power(a, n-1);
}

/// a^n = (a^(n/2))^2 if(n is even) else a^n = a((a^(n/2))^2)
// Steps reduced to log(N) base 2;
int fastPower(int a, int n){
    if(n == 0) return 1;
    int smaller_ans = fastPower(a, n/2);
    smaller_ans *= smaller_ans;
    if(n&1){
        //odd
        return smaller_ans*a;
    }
    return smaller_ans;
}

int main(){
    int a, n;
    cin>>a>>n;
    cout<<fastPower(a, n)<<endl;
    return 0;
}