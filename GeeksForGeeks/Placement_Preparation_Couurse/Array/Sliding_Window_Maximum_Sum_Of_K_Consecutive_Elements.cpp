#include<bits/stdc++.h>
using namespace std;

int findMaximumSum(int arr[], int N, int k){
    int p1 = 0;
    int p2 = k-1;
    int window_sum = 0, current_sum = 0;
    for(int i=p1;i<=p2;i++){
        window_sum += arr[i];
    }
    int max_sum = window_sum;
    p1++; p2++;
    while(p2 <= N-1){
        current_sum = window_sum - arr[p1-1] + arr[p2];
        window_sum = current_sum;
        if(current_sum > max_sum){
            max_sum = current_sum;
        }
        p1++;
        p2++;
    }
    return max_sum;
}
int main(){
    int N;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int maxSum = findMaximumSum(arr, N, k);
    cout<<maxSum<<endl;
    return 0;
}