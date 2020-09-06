#include<bits/stdc++.h>
using namespace std;

// Algo: Linear search using recursion
int findElementLastOccurence(int arr[], int i, int n, int target, int &ans){
    if(i == n) return -1;

    if(arr[i] == target) ans = i;

    return findElementLastOccurence(arr, i+1, n, target, ans);
}

// Variation 2
int findElementLastOccurence2(int arr[], int n, int target){
    if(n == 0) return -1;

    int i = findElementLastOccurence2(arr+1, n-1, target);

    if(i == -1){
        if(arr[0] == target){
            return 0;
        }else{
            return -1;
        }
    }

    return i+1;
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

    int index = -1;
    findElementLastOccurence(arr, 0, n, target, index);

    cout<<index<<endl;


    return 0;
}