#include<iostream>
using namespace std;

bool isArrayIncreasinglySorted(int arr[], int n){
    if(n==0 or n==1)
        return true;
    
    if(arr[0] < arr[1] and isArrayIncreasinglySorted(arr+1, n-1)) // Note this line -> Important
        return true;
    return false;
}

int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    bool result = isArrayIncreasinglySorted(arr, n);

    cout<<result<<endl;

    return 0;
}