#include<iostream>
using namespace std;

int main(){
    int N, P;
    cin>>N>>P;

    float ans =0;
    float inc = 1.0;

    while(P>=0){
        while(ans*ans<=N){
            ans += inc;
        }
        ans = ans-inc;
        inc = inc/10;
        P--;
    }

    cout<<ans<<endl;

    return 0;
}