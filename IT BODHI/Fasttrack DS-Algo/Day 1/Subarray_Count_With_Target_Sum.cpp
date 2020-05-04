/*
Total subarray present: Sigma N or nC2+N
1) Finding all subarrays - O(N3)
2) O(N2) - Implemented
2) O(N) - Implemented
*/
#include<bits/stdc++.h>
using namespace std;

int findSubarrayCountN2(int arr[], int N, int key){
    int count = 0;
    for(int i=0;i<N;i++){
        int sum = 0;
        for(int j=i;j<N;j++){
            sum += arr[j];
            if(sum == key)
                count++;
        }
    }
    return count;
}
int findSubarrayCountN(int arr[], int N, int key){
    unordered_map<int, int> hashMap;
    int cumSum = 0, count = 0;
    hashMap[0] = 1;
    for(int i=0;i<N;i++){
        cumSum += arr[i];
        if(hashMap.find(cumSum-key) == hashMap.end()){
            hashMap[cumSum] = 1;
        }else{
            count += hashMap[cumSum-key];
            hashMap[cumSum]++;
        }
    }
    return count;
}
int main(){
    int N;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;

    int count = findSubarrayCountN(arr, N, key);

    cout<<"Count: "<<count<<endl;
    return 0;
}