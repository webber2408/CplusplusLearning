/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3
Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.

Implemented Solution:
Time Complexity: O(n)
Space Complexity: O(1)
*/
#include<bits/stdc++.h>
using namespace std;

int findDuplicate(int arr[], int N){
    int duplicate = 0;
    for(int i=0;i<N;i++){
        if(arr[abs(arr[i])] > 0){
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        }else{
            duplicate = abs(arr[i]); //It is possible that some previous element has made it negative.
        }
    }
    return duplicate;
}
int main(){
    int N;
    cin>>N;
    int arr[N];

    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    int answer = findDuplicate(arr, N);
    cout<<answer<<endl;
    return 0;
}