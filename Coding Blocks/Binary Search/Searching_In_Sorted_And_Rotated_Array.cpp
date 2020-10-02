#include<bits/stdc++.h>
using namespace std;

void findElement(int arr[], int N, int target){
    int l = 0, r = N-1, m = -1;
    bool isFound = false;

    while(l<=r){
        m = l + (r-l)/2;
        // cout<<"l"<<l<<"r"<<r<<"m"<<m<<endl;
        if(arr[m] == target){
            isFound = true;
            cout<<"Found";
            break;
        }
        if(arr[l] <= arr[m]){
            // Left part of mid is sorted
            if(arr[l] <= target && target <= arr[m]){
                r = m-1;
            }else{
                l = m+1;
            }
        }else if(arr[m] <= arr[r]){
            //Right part of the mid is sorted
            if(arr[m] <= target && target <= arr[r]){
                l = m+1;
            }else{
                r = m-1;
            }
        }
    }

    if(!isFound){
        cout<<"Element not present in the array";
    }

    return;
}

int main(){

    int N;
    cin>>N;
    int arr[N];
    
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }

    int target;
    cin>>target;

    findElement(arr, N, target);

    return 0;
}