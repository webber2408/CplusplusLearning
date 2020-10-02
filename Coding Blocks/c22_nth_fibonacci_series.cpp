#include<iostream>
using namespace std;

/*0 1 1 2 3 5 */

int getNthFibonacciNumber(int N){
    int a = 0;
    int b = 1;
    int c;

    for(int i = 0;i<N-1;i++){
        c = a+b;
        a = b;
        b = c;
    }

    return c;
}
int main(){
    int N;
    cin>>N;

    cout<<getNthFibonacciNumber(N)<<endl;
    return 0;
}