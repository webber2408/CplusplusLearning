//complexity
//if sorted o(n)
// if not o(nlogn)// to sort  + o(n) = o(n) as bigger
#include<bits/stdc++.h>
using namespace std;
int findSum(int [],int , int ,int );
int i,j;
int main(){
    cout<<"Enter input array size:"<<endl;
    int n;
    cin>>n;
    cout<<"Enter input array:"<<endl;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    cout<<"Enter k(sum):"<<endl;
    int k;
    cin>>k;
    findSum(arr,0,n-1,k);
}
int findSum(int a[],int i,int j,int k){

    if(i>j){
        cout<<"Sum not possible"<<endl;
        return -1;
    }
    if(a[i]+a[j] > k){
        findSum(a,i,j-1,k);
    }else if(a[i]+a[j] < k){
        findSum(a,i+1,j,k);
    }else{
        cout<<"Sum possible"<<endl;
        cout<<"A = "<<a[i]<<endl;
        cout<<"B = "<<a[j]<<endl;
        return 1;
    }
}
