#include<iostream>
using namespace std;

int main(){
    int num;
    cin>>num;

    if(num < 2){
        cout<<"false"<<endl;
        return 0;
    }

    if(num == 2){
        cout<<"true"<<endl;
        return 0;
    }

    for(int i=2; i<num; i++){
        if(num%i==0){
            cout<<"false"<<endl;
            return 0;
        }
    }

    cout<<"true"<<endl;
    return 0;
}