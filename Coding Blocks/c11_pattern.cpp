#include<iostream>
using namespace std;

int main(){
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        int j;
        //Number of spaces
        for(j=1;j<=N-i;j++){
            cout<<" ";
        }
        //Numbers (i times)
        int count =i;
        for(j=1;j<=i;j++){
            cout<<count;
            count += 1;
        }
        count -= 2;
        //Numbers (i-1) times
        for(j=1;j<=i-1;j++){
            cout<<count;
            count -= 1;
        }
        cout<<endl;
    }
    return 0;
}