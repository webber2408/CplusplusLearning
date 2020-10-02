#include<bits/stdc++.h>
using namespace std;

bool isPossibleToDivideBooks(int arr[], int n, int m, int curr_min){
    int studentUsed = 1;
    int pages_reading = 0;

    for(int i=0; i<n; i++){
        if(pages_reading + arr[i] > curr_min){
            studentUsed++;
            pages_reading = arr[i];

            if(studentUsed > m){
                return false;
            }
        }else{
            pages_reading += arr[i];
        }
    }

    return true;
}

int findMinPages(int arr[], int n, int m){
    int sum = 0;
    
    if(n<m){
        return -1;
    }

    for(int i=0; i<n; i++){
        sum += arr[i];
    }

    int l = arr[n-1];
    int r = sum;

    int ans = INT_MAX;

    while(l<=r){
        int mid = l + (r-l)/2;
        if(isPossibleToDivideBooks(arr, n, m, mid)){
            ans = min(ans, mid);
            r = mid-1;
        }else{
            l = mid+1;
        }
    }

    return ans;
}

int main(){
    int t;
    cin>>t;

    for(int i=0; i<t; i++){
        int n, m;
        cin>>n>>m;

        int arr[n];

        for(int j=0; j<n; j++){
            cin>>arr[j];
        }

        cout<<findMinPages(arr, n, m)<<endl;
    }

    return 0;
}