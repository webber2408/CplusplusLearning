/*
Given an array S of size N , check if it is possible to split sequence into two sequences -
s1 to si and si+1 to sN such that first sequence is strictly decreasing 
and second is strictly increasing. Print true/false as output.

Input Format
First line contains a single integer N denoting the size of the input.
Next N lines contain a single integer each denoting the elements of the array S.

Constraints
0 < N < 1000 Each number in sequence S is > 0 and < 1000000000

Output Format
Print boolean output - "true" or "false" defining whether the sequence is increasing - decreasing or not.

Sample Input
5 
1 
2 
3 
4 
5
Sample Output
true
Explanation
Carefully read the conditions to judge which all sequences may be valid. Don't use arrays or lists.
*/
#include<iostream>
#include<climits>
using namespace std;

int main(){
    int N;
    cin>>N;
    int val;

    int lastValue = INT_MAX;
    bool isDecreasing = true;
    for(int i=0; i<N; i++){
        cin>>val;
        if(val == lastValue){
            cout<<"false"<<endl;
            return 0;
        }
        if(val > lastValue){
            isDecreasing = false;
        }
        else if(!isDecreasing && val < lastValue){
            cout<<"false"<<endl;
            return 0;
        }
        lastValue = val;
    }
    cout<<"true"<<endl;
    return 0;
}






