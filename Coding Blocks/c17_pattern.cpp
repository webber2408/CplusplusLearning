#include<iostream>
using namespace std;

int main(){
    int N;
    cin>>N;

    cout<<1<<endl;

    int i=1;
    while(i<N){
        int value = i%2==0?1:0;
        int j=0;
        while(j<i+2){
            cout<<value;
            value = 1-value;
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}
// int main(){
//     int N,j=0;
//     cin>>N;

//     cout<<1<<endl;
//     int bit;

//     for(int i=2;i<=N;i++){
//         if(i%2==0){
//             //even
//             cout<<0;
//             bit = 0;
//             j = 0;
//             while(j<i){
//                 // switch(bit){
//                 //     case 1: bit=0;break;
//                 //     case 0: bit=1;break;
//                 // }
//                 bit = 1-bit;
//                 cout<<bit;
//                 j++;
//             }
//             cout<<endl;
//         }else{
//             //odd
//             cout<<1;
//             bit = 1;
//             j = 0;
//             while(j<i){
//                 // switch(bit){
//                 //     case 1: bit=0;break;
//                 //     case 0: bit=1;break;
//                 // }
//                 bit = 1-bit;
//                 cout<<bit;
//                 j++;
//             }
//             cout<<endl;
//         }
//     }

//     return 0;
// }

