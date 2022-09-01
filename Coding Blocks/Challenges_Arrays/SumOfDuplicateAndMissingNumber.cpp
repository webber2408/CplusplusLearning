#include<bits/stdc++.h>
using namespace std;

int find_mistake(int arr[], int n){
    int total_sum = n*(n+1)>>1, arr_sum = 0, duplicate_no = 0;
    unordered_map<int, int> hashMap;
    for(int i=0; i<n; i++){
        if(hashMap.find(arr[i]) == hashMap.end()) hashMap.insert(make_pair(arr[i], 1))
        else duplicate_no = arr[i];
        arr_sum += arr[i];
    }
    return duplicate_no + (total_sum - (arr_sum - duplicate_no));
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<find_mistake()<<endl;
    return 0;
}