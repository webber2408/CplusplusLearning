#include<bits/stdc++.h>
using namespace std;
int binarySearch(int [],int,int,int);
int mid;
int main(){
    cout<<"Enter array size:"<<endl;
    int n;
    cin>>n;
    cout<<"Enter array:"<<endl;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter element to search for :"<<endl;
    int ele;
    cin>>ele;
    binarySearch(arr,0,n,ele);
}
int binarySearch(int arr[],int l,int h,int ele)
{
    mid  = (l+h)/2;
    if(l<=h){
        if(arr[mid] == ele){
            cout<<"Found "<<ele<<" at position "<<mid+1;
            return 0;
        }
        else{

            if(arr[mid] < ele){
                binarySearch(arr,mid+1,h,ele);
            }
            else if(arr[mid] > ele){
                binarySearch(arr,l,mid-1,ele);
            }
        }
    }
    else{
        cout<<"Not found";
        return -1;
    }
}
