/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums is a non decreasing array.
-10^9 <= target <= 10^9
*/
#include<bits/stdc++.h>
using namespace std;

int getFirstOccurence(int arr[], int N, int target){
    int l = 0, r = N-1, m = -1, ans = -1;
    while(l <= r){
        m = l + (r-l)/2;
        if(arr[m] == target){
            ans = m;
            r = m-1;
        }else if(arr[m] > target){
            r = m-1;
        }else{
            l = m+1;
        }
    }
    return ans;
}
int getLastOccurence(int arr[], int N, int target){
    int l = 0, r = N-1, m = -1, ans = -1;
    while(l <= r){
        m = l + (r-l)/2;
        if(arr[m] == target){
            ans = m;
            l = m+1;
        }else if(arr[m] > target){
            r = m-1;
        }else{
            l = m+1;
        }
    }
    return ans;
}

vector<int> getFirstAndLastOccurence(int arr[], int N, int target){
    vector<int> result;
    result.push_back(getFirstOccurence(arr, N, target));
    result.push_back(getLastOccurence(arr, N, target));
    return result;
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

    vector<int> result = getFirstAndLastOccurence(arr, N, target);

    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0;
}
