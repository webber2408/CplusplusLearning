/*
Take N (number of rows), print the following pattern (for N = 4)
0
1 1
2 3 5
8 13 21 34

Input Format
Constraints
0 < N < 100

Output Format
Sample Input
4
Sample Output
0 
1    1 
2    3     5 
8   13    21    34
Explanation
Each number is separated from other by a tab. For given input n, You need to print n(n+1)/2 fibonacci numbers. Kth row contains , next k fibonacci numbers.
*/

#include<iostream>
using namespace std;

long long getNthFibNum(int n){
    long long a=0, b=1, c=0;
    if(n==0) return 0;
    if(n==1) return 1;
    for(int i=2;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}
int main(){
    int N;
    cin>>N;
    int count = 0;
    for(int i=1;i<=N;i++){
        int j = i;
        while(j>0){
            cout<<getNthFibNum(count)<<'\t';
            j--;
            count++;
        }
        cout<<endl;
    }
}