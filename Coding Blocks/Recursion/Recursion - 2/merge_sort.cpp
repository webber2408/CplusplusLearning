#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &a, int s, int m, int e){

    int n1 = m-s+1;
    int n2 = e-m;
    int L[n1], R[n2];

    for(int i=0; i<n1; i++)
        L[i] = a[s+i];
    for(int i=0; i<n2; i++)
        R[i] = a[m+1+i];

    int p1 = 0, p2 = 0, k = s;
    
    while(p1<n1 && p2<n2){
        if(L[p1] > R[p2])
            a[k++] = R[p2++];
        else
            a[k++] = L[p1++];
    }

    while(p1<n1)
        a[k++] = L[p1++];
    while(p2<n2)
        a[k++] = R[p2++];
}

void mergeSort(vector<int> &nums, int s, int e){
    if(s>=e) return;

    int m = s + (e-s)/2;

    mergeSort(nums, s, m);
    mergeSort(nums, m+1, e);

    //Merge
    merge(nums, s, m, e);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    int num;
    for(int i=0; i<n; i++){
        cin>>num;
        arr.push_back(num);
    }

    mergeSort(arr, 0, n-1);

    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}