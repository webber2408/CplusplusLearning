/*
Take as input N, the size of array. Take N more inputs and store that in an array. Take as input “target”, a number. Write a function which prints all pairs of numbers which sum to target.

Input Format
The first line contains input N. Next N lines contains the elements of array and (N+1)th line contains target number.

Constraints
Length of the arrays should be between 1 and 1000.

Output Format
Print all the pairs of numbers which sum to target. Print each pair in increasing order.

Sample Input
5
1
3
4
2
5
5
Sample Output
1 and 4
2 and 3
Explanation
Find any pair of elements in the array which has sum equal to target element and print them.
*/
#include<bits/stdc++.h>
using namespace std;

void findPairs(int arr[], int N, int target){
    sort(arr, arr+N);
    int x = 0, y = N-1;
    while(x<y){
        if(arr[x]+arr[y] == target){
            cout<<arr[x]<<" and "<<arr[y]<<endl;
            x++;
        }else if(arr[x]+arr[y] < target){
            x++;
        }else if(arr[x]+arr[y] > target){
            y--;
        }
    }
}

int main(){
    int N;
    cin>>N;
    int arr[N];

    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    int target;
    cin>>target;

    findPairs(arr, N, target);
    
    return 0;
}