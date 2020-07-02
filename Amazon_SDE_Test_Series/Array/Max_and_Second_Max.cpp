/*
Max and Second Max
Given an array arr[] of size N of positive integers which may have duplicates. The task is to find maximum and second maximum from the array, and both of them should be distinct, so If no second max exists, then second max will be -1.

Input Format:
First line of input contains number of testcases T. For each testcase, first line of input contains size of array N, next line contains array elements.

Output Format:
For each testcase, print the maximum and second maximum from the array. IF no second max exists, print "-1" for second max.

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= arr[i] <= 106

User Task:
The task is to complete the function largestAndSecondLargest(), which should print maximum and second maximum element from the array.

Example:
Input:
3
5
1 2 3 4 5
3
2 1 2
2
5 5

Output:
5 4
2 1
5 -1

Explanation:
Testcase 1: From the given array elements, 5 is the largest and 4 is the second largest.
Testcase 2: From the given array elements, 2 is the largest and 1 is the second largest.
Testcase 3: From the given array elements, 5 is the largest and -1 is the second largest.
*/
#include<bits/stdc++.h>
using namespace std;

void largestAndSecondLargest(int arr[], int n){
    int largest = INT_MIN;
    for(int i=0;i<n;i++)
        if(arr[i] > largest)
            largest = arr[i];
    int second_largest = INT_MIN;
    for(int i=0;i<n;i++)
        if(arr[i] > second_largest && arr[i] < largest)
            second_largest = arr[i];
    if(second_largest == INT_MIN)
        second_largest = -1;
    cout<<largest<<" "<<second_largest<<endl;
    return;
}
void largestAndSecondLargestOptimised(int arr[], int n){
    int max = INT_MIN, max2 = INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i] > max){
            max2 = max;
            max = arr[i];
        }else{
            if(arr[i] > max2 && arr[i] < max){
                max2 = arr[i];
            }
        }
    }
    if(max2 == INT_MIN)
        max2 = -1;
    cout<<max<<" "<<max2<<endl;
}
int main(){

    int cases;
    cin>>cases;

    while(cases--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        largestAndSecondLargestOptimised(arr, n);
    }

    return 0;
}