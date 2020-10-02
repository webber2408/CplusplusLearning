#include<bits/stdc++.h>
using namespace std;

int main(){

    int N, p;
    cin>>N;
    cin>>p;

    int l = 0, r = N;
    float ans = -1;

    while(l<=r){
        long long int m = l + (r-l)/2;
        if(m*m == N){
            ans = m;
            break;
        }
        else if(m*m < N){
            ans = m;
            l = m+1;
        }else{
            r = m-1;
        }
    }

    cout<<ans<<endl;

    float inc = 0.1;
    for(int i=0; i<p; i++){

        while(ans*ans <= N){
            ans = ans + inc;
        }

        ans = ans - inc;
        inc /= 10;
    }

    cout<<ans<<endl;

    return 0;
}