/*
    Incomplete
*/
#include<iostream>
#include<climits>
using namespace std;

void longestSubArray(int arr[], int n){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            cout<<i<<"->"<<j<<endl;
        }
    }
}
int main(){
    int N;
    cin>>N;

    int arr[N];
    cout<<"Enter array: "<<endl;

    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    longestSubArray(arr, N);

    return 0;
}
