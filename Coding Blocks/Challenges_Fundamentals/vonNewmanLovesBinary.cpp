/* Convert Binary to Decimal Representation */
/* O(N*Max_Digits)*/
#include<iostream>
using namespace std;

int main(){
    int N,num;
    cin>>N;
    int sum = 0;

    for(int i=0;i<N;i++){
        cin>>num;
        int j=1;
        while(num>0){
            sum += (num%10)*j;
            j *= 2;
            num = num/10;
        }
        cout<<sum<<endl;
        sum = 0;
    }

    return 0;
}