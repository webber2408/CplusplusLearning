#include<bits/stdc++.h>
using namespace std;
void removeRepitition(int [],int);
int main(){
    cout<<"Enter array size:"<<endl;
    int n;
    cin>>n;
    cout<<"Enter array:"<<endl;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    removeRepitition(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"->";
    }
}
void removeRepitition(int arr[],int n){
    int wp=0;
    int lastV = -1;
    for(int i=0;i<n;i++){
        if(arr[i] != lastV){
            arr[wp] = arr[i];
            lastV = arr[i];
            wp++;
        }
    }
    for(int i=wp;i<n;i++){
        arr[i] = -1;
    }
}
