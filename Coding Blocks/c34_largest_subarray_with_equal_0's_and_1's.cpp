#include<iostream>
#include<unordered_map>
#include<climits>
using namespace std;

void getLargestSubArray(int arr[], int n){
    int sum = 0, max_length = INT_MIN, start_index = -1, end_index = -1;
    unordered_map<int, int> storeMap;

    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            sum += -1;
        }else{
            sum += 1;
        }

        //for case when start index is the first index
        if(sum == 0){
            start_index = 0;
            end_index = i;
            max_length = max(max_length, i+1);
        }

        //for cases when start index is other than the first index
        if(storeMap.find(sum) == storeMap.end()){
            storeMap[sum] = i;
        }else{
            if((i - storeMap[sum]) > max_length){
                max_length = i - storeMap[sum];
                start_index = storeMap[sum]+1;
                end_index = i;
            }
        }
    }

    if(max_length == INT_MIN){
        max_length = 0;
        cout<<"Max length: "<<max_length<<endl;
    }else{        
        cout<<"Max length: "<<max_length<<endl;
        cout<<"Start Index: "<<start_index<<endl;
        cout<<"End Index: "<<end_index<<endl;
    }

    return;
}

int main(){
    int N;
    cin>>N;

    int arr[N];

    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    getLargestSubArray(arr, N);

    return 0;
}