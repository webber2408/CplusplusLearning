#include<iostream>
using namespace std;

void printPattern(int N){
    for(int i=N;i>0;i--){
        char ch = 'A';
        for(int j=0;j<i;j++){
            cout<<ch;
            ch++;
        }
        cout<<endl;
    }
}
int main(){
    int N;
    cin>>N;
    printPattern(N);
    return 0;
}