/*
Help Manmohan to print pattern of a given number. See the output pattern for given input n = 5.

Input Format
Single integer N denoting number of lines of the pattern.

Constraints
N<=1000

Output Format
Pattern.

Sample Input
5
Sample Output
1
11
202
3003
40004
Explanation
If row number is n (>1), total character is n. First and last character is n-1 and rest are 0.
*/

#include<iostream>
using namespace std;

int main(){
    int N;
    cin>>N;

    cout<<1<<endl;
    for(int i=2;i<=N;i++){
        int j= i;
        cout<<i-1;
        while(j-2>0){
            cout<<0;
            j--;
        }
        cout<<i-1<<endl;
    }
    return 0;
}