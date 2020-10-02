/*
Given a number N (denoting one of the legs of the triangle), Print its Pythagoras pair in increasing order 
if they exist. Otherwise, print "-1".

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
#include<cmath>
using namespace std;

int main(){
    long long int a;
    cin>>a;

    if(a<3){
        cout<<-1<<endl;
        return 0;
    }

    long long int b = 0, c = 0;

    if(a%2==0){
        //Even
        c = (1ll * a * a)/4 + 1;
        b = c - 2;
    }else{
        //Odd
        b = (1ll * a * a - 1)/2;
        c = (1ll * a * a + 1)/2;
    }

    cout<<b<<" "<<c<<endl;
    return 0;
}
