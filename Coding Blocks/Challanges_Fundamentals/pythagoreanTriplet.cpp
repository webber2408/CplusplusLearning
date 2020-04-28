/*
Given a number N (denoting one of the legs of the triangle), Print its Pythagoras pair in increasing order if they exist. Otherwise, print "-1".

Input Format
A single integer N

Constraints
N <= 10^9

Output Format
Two numbers X and Y denoting the rest of the numbers of the Pythagorean triplet in increasing order.

Sample Input
3
Sample Output
4 5

Solution:

let the number given be a

then if a<3 then no triplets will form

if a is even, then b=(a/2)^2 -1 , c=b+2

if a is odd, then b=(a^2–1)/2, c=b+1

*/
#include<iostream>
using namespace std;

int main(){
    int N;
    cin>>N;

    if(N<3){
        cout<<-1<<endl;
        return 0;
    }

    int b = 0, c = 0;

    if(N%2==0){
        //Even
        b = (N/2)*(N/2);
        c = b + 2;
    }else{
        //Odd
        b = (N*N-1)/2;
        c = b + 1;
    }

    cout<<b<<" "<<c<<endl;
    return 0;
}
// int main(){
//     int N;
//     cin>>N;
//     int base = 1;
//     if(N <= 1){
//         cout<<-1<<endl;
//         return 0;
//     }
//     while(true){
//         // cout<<"Hello";
//         int hSquared = base*base + N*N;
        
//         int ans = 1;
//         while(ans*ans != hSquared){
//             if(ans*ans > hSquared){
//                 cout<<-1;
//                 cout<<ans;
//                 cout<<base;
//                 return 0;
//             }
//             ans += 1;
//         }
//         if(ans*ans == hSquared){
//             cout<<base<<" "<<ans<<endl;
//             break;
//         }
//         base += 1;
//     }
//     return 0;
// }