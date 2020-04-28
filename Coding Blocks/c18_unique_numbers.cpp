#include<iostream>
using namespace std;

int main(){
    int N,num;
    cin>>N;
    int buff[9999];
    for(int i=0;i<N;i++){
        buff[i] = 0;
    }
    cout<<"Enter Array"<<endl;
    for(int i=0;i<N;i++){
        cin>>num;
        buff[num]+= 1;
    }
    for(int i=0;i<9999;i++){
        if(buff[i] == 1){
            cout<<"Ans: "<<i;
            break;
        }
    }

}