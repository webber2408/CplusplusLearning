/*Given N, help Manmohan to print pattern upto N lines. For eg For N=6 , following pattern will be printed.

1
11
111
1001
11111
100001

Input Format
Single number N.

Constraints
N<=1000

Output Format
Pattern corresponding to N.

Sample Input
6
Sample Output
1 
11
111 
1001 
11111
100001
Explanation
For every odd number row print 1, odd number of times and for every even number row , print first and last character as 1 and rest of middle characters as 0. */

#include<iostream>
using namespace std;

int main(){
    int N;
    cin>>N;
    cout<<1<<endl;
    for(int i=2;i<=N;i++){
        int j=i;
        cout<<1;
        if(i%2==0){
            while(j-2>0){
                cout<<0;
                j--;
            }
        }else{
            while(j-2>0){
                cout<<1;
                j--;
            }
        }        
        cout<<1<<endl;
    }
    return 0;
}