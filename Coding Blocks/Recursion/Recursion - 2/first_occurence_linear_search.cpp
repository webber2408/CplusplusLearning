#include<bits/stdc++.h>
using namespace std;

// Algo: Linear Search using Recursion
int findElementFirstOccurence(int arr[], int i, int n, int target){
    //base case
    if(i == n) return -1;
    //favourable case
    if(arr[0] == target) return i;

    return findElementFirstOccurence(arr+1, i+1, n, target);
}

// Variation 2
int findElementFirstOccurence2(int arr[], int i, int n, int target){
    //base case
    if(i == n) return -1;
    //favourable case
    if(arr[i] == target) return i;

    return findElementFirstOccurence2(arr, i+1, n, target);
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

    int index = findElementFirstOccurence(arr, 0, n, target);

    cout<<index<<endl;


    return 0;
}