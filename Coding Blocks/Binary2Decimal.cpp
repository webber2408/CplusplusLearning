#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int pow = 1, ans = 0;
    while(n>0){
        ans += (n%10)*pow;
        n = n/10;
        pow = pow*2;
    }

    cout<<ans<<endl;
}