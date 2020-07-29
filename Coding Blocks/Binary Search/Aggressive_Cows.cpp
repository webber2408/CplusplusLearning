/*
Farmer John has built a new long barn, with N stalls.
Given an array of integers A of size N where each element of the array represents the location of the stall,
and an integer B which represent the number of cows.

His cows don’t like this barn layout and become aggressive towards each other once put
into a stall. To prevent the cows from hurting each other, John wants to assign the cows to the stalls,
such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

Input Format

The first argument given is the integer array A.
The second argument given is the integer B.
Output Format

Return the largest minimum distance possible among the cows.
Constraints

2 <= N <= 100000
0 <= A[i] <= 10^9
2 <= B <= N
For Example

Input 1:
    A = [1, 2, 3, 4, 5]
    B = 3
Output 1:
    2

Input 2:
    A = [5, 17, 100, 11]
    B = 2
Output 2:
    95
*/
#include<bits/stdc++.h>
using namespace std;

bool canPlaceCows(int stalls[], int n, int c, int min_sep){
    int last_cow = stalls[0];
    int cowCount = 1;

    for(int i=0; i<n; i++){
        if(stalls[i] - last_cow >= min_sep){
            last_cow = stalls[i];
            cowCount++;
            if(cowCount == c){
                return true;
            }
        }
    }

    return false;
}

int findLargestMinimumDistance(int stalls[], int n, int c){
   int l = 0, r = stalls[n-1]-stalls[0], ans = 0;

   while (l <= r){
        int m = l + (r-l)/2;
        bool cowsRakhPaye = canPlaceCows(stalls, n, c, m);
        if(cowsRakhPaye){
            ans = m;
            l = m+1;
        }else{
            r = m-1;   
        }
   }
   
   return ans;
}

int main(){
    int N;
    cin>>N;
    int arr[N];

    for(int i=0; i<N; i++){
        cin>>arr[i];
    }

    int c;
    cin>>c;

    cout<<findLargestMinimumDistance(arr, N, c)<<endl;

    return 0;
}