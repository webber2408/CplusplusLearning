/*
Take N (number in decimal format). Write a function that converts it to octal format. Print the value returned.

Input Format
Constraints
0 < N <= 1000000000

Output Format
Sample Input
63
Sample Output
77
Explanation
Both input and output are integers
*/
#include<iostream>
using namespace std;

int main(){
    int N;
    cin>>N;

    int ans = 0;
    while(N > 0){
        ans = ans*10 + (N%8);
        N = N/8;
    }

    int revAns = 0;
    while(ans > 0){
        revAns = revAns*10 + ans%10;
        ans /= 10;
    }

    cout<<revAns<<endl;

    return 0;
}




