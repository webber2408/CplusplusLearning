#include<iostream>
using namespace std;

int getTrailingZeros(int N){
    int D = 5, zerosCount = 0;
    while(N/D>0){
        zerosCount += N/D;
        D *= 5;
    }
    return zerosCount;
}
int main(){
    int N;
    cin>>N;
    cout<<"Trailing zeros in "<<N<<" are "<<getTrailingZeros(N)<<endl;
    return 0;
}