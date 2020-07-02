/*
Third largest element
Given an array of distinct elements. Your task is to find the third largest element in it. You have to complete the function thirdLargest which takes two argument. The first argument is the array a[] and the second argument is the size of the array (n). The function returns an integer denoting the third largest element in the array a[]. The function should return -1 if there are less than 3 elements in input.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case is N, size of array. The second line of each test case contains N space separated values of the array a[].

Output:
Output for each test case will be the third-largest element of the array.

Your Task:
You don't need to read input or print anything. Your task is to complete the function thirdLargest() with accepts the array and number of elements as arguments and returns the third largest element of the array.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 105
1 ≤ A[i] ≤ 105

Example(To be used for only expected output):
Input:
2
5
2 4 1 3 5
2
10 2
Output:
3
-1
*/
#include<bits/stdc++.h>
using namespace std;

int getThirdLargestElement(int arr[], int N){
    if(N<3)
        return -1;
    sort(arr, arr+N);
    return arr[N-3];
}
int getThirdLargestElementN(int arr[], int N){
    if(N==2){
        return arr[0] > arr[1]? arr[0]: arr[1];
    }else if(N==1){
        return arr[0];
    }else if(N==0){
        return 0;
    }
    int first = arr[0], second = INT_MIN, third = INT_MIN;
    for(int i=0;i<N;i++){
        if(arr[i] > first){
            third = second;
            second = first;
            first = arr[i];
        }else if(arr[i] > second){
            third = second;
            second = arr[i];
        }else if(arr[i] > third){
            third = arr[i];
        }
    }
    return third;
}
int main(){
    int cases;
    cin>>cases;
    for(int i=0;i<cases;i++){
        int N;
        cin>>N;
        int arr[N];
        for(int j=0;j<N;j++){
            cin>>arr[j];
        }
        int result = getThirdLargestElementN(arr,N);
        cout<<result<<endl;
    }
    return 0;
}