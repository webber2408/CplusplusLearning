#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int *a, int n){
    if(n==1) return;

    for(int j=0; j<n-1; j++){
        if(a[j] > a[j+1]) swap(a[j], a[j+1]);
    }

    bubbleSort(a, n-1);
}

// Great example of recursion
void bubble_sort_recursive(int a[], int j, int n){
    if(n == 1)
        return;
        
    if(j == n-1)
        return bubble_sort_recursive(a, 0, n-1);
    
    if(a[j] > a[j+1]){
        swap(a[j], a[j+1]);
    }

    return bubble_sort_recursive(a, j+1, n);
}

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    bubble_sort_recursive(arr, 0, n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;

    return 0;
}