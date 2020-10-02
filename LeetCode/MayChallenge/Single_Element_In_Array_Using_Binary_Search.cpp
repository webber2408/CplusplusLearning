#include<bits/stdc++.h>
using namespace std;

int N;
int findSingleElement(int arr[], int l, int r){
    if(r<l){
        return 0;
    }
    if(l == r && ( (l-1 >= 0 && arr[l] == arr[l-1]) || (r+1 < N && arr[r] == arr[r+1]))){
        return 0;
    }
    int m = (l+r)/2;
    if(m-1 >= 0 && arr[m] == arr[m-1]){
        return findSingleElement(arr, l, m-2) + findSingleElement(arr, m+1, r);
    }else if(m+1 < N && arr[m] == arr[m+1]){
        return findSingleElement(arr, l, m-1) + findSingleElement(arr, m+2, r);
    }else{
        return arr[m];
    }
}
int main(){
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    cout<<findSingleElement(arr, 0, N-1);
    return 0;
}