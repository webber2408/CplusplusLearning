#include<bits/stdc++.h>
using namespace std;

// Variation 1 -> Print in increasing order of index | Print going forward
void printAllOccurence(int *arr, int i, int n, int target){
    if(i == n) return;
    if(arr[i] == target) cout<<i<<" ";
    return printAllOccurence(arr, i+1, n, target);
}

// Variation 2 -> Print in decreasing order | Print coming back
void printAllOccurence2(int *arr, int n, int target){
    if(n < 0) return;

    printAllOccurence2(arr+1, n-1, target);

    if(arr[0] == target) cout<<
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

    printAllOccurence(arr, 0, n, target);

    cout<<endl;

    return 0;
}