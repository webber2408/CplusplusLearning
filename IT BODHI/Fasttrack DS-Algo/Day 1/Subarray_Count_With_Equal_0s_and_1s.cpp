#include<bits/stdc++.h>
using namespace std;

int getCount(int arr[], int N){
    for(int i=0;i<N;i++){
        if(arr[i] == 0)
            arr[i] = -1;
    }

    int cumSum = 0, count = 0, key = 0;
    unordered_map<int, int> hashMap;
    for(int i=0;i<N;i++){
        cumSum += arr[i];
        if(cumSum == key)
            count++;
        
        if(hashMap.find(cumSum-key) != hashMap.end())
            count += hashMap[cumSum-key];
        
        hashMap[cumSum]++;
    }

    return count;
}
int main(){

    int N;
    cout<<"Enter size:"<<endl;
    cin>>N;
    int arr[N];
    cout<<"Enter array with only 0s and 1s:"<<endl;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    int count = getCount(arr, N);

    cout<<"Total subarray count with equal 0s and 1s:"<<endl;
    cout<<count<<endl;

    return 0;
}