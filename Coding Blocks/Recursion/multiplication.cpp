#include<iostream>
using namespace std;

int multiply(int n1, int n2){
    if(n2==1) return n1;
    return n1 + multiply(n1, n2-1);
}

int main(){
    int n1, n2;
    cin>>n1>>n2;

    int ans = multiply(n1, n2);

    cout<<ans<<endl;

    return 0;
}