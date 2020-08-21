#include<iostream>
using namespace std;

bool search(int arr[], int s, int e, int target){
    if(s>e) return false;
    int mid = (s+e)/2;
    if(arr[mid] == target)  return true;
    else if(arr[mid] < target) return search(arr, mid+1, e, target);
    else return search(arr, s, mid-1, target);
}

int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int target;
    cin>>target;

    bool result = search(arr, 0, n-1, target);

    cout<<result<<endl;

    return 0;
}