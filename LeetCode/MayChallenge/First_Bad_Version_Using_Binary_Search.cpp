/*
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

Example:

Given n = 5, and version = 4 is the first bad version.

call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true

Then 4 is the first bad version. 
*/
#include<bits/stdc++.h>
using namespace std;

bool isBadVersion(int version){
    int badVersionArray[3] = {6, 7, 8};
    for(int i=0;i<3;i++){
        if(version == badVersionArray[i]){
            return true;
        }
    }
    return false;
}
int getFirstBadVersion(int arr[], int N){
    int l = 0, r = N-1, m = 0, fbv = -1;
    while(l<=r){
        m = l + ((r-l)/2);
        if(isBadVersion(arr[m])){
            r = m-1;
            fbv = arr[m];
        }else{
            l = m+1;
        }
    }
    return fbv;
}
int main(){
    int N;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    cout<<getFirstBadVersion(arr, N);
    return 0;
}