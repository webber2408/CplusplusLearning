#include<bits/stdc++.h>
using namespace std;
void findSum(int [],int , int);
int binarySearch(int [],int ,int ,int);
int mid;
int main(){
    cout<<"Enter sorted input array size:"<<endl;
    int n;
    cin>>n;
    cout<<"Enter sorted input array:"<<endl;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter k(sum):"<<endl;
    int k;
    cin>>k;
    findSum(arr,n,k);
}
int binarySearch(int arr[],int l,int h,int ele)
{
    mid  = (l+h)/2;
    if(l<=h){
        if(arr[mid] == ele){

            return 1;
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

        return 0;
    }
}
void findSum(int arr[],int n,int k){
    int temp;
    int i;
    for( i=0;i<n;i++){
        temp = k-arr[i];
        if(binarySearch(arr,i+1,n,temp)){
            cout<<"Sum possible"<<endl;
            cout<<"A = "<<arr[i]<<endl;
            cout<<"B = "<<temp<<endl;
            break;
        }
    }
    if(i==n){
        cout<<"Sum not possible"<<endl;
    }
}
