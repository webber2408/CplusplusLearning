#include<iostream>
using namespace std;

int main(){
    int N,i;
    cin>>N;

    for(i=2;i<=N-1;i++){
        if(N%i==0){
            cout<<"Not Prime"<<endl;
            break;
        }
    }
    if(i==N){
        cout<<"Prime"<<endl;
    }
}