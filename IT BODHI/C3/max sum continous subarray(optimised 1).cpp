#include<bits/stdc++.h>
using namespace std;
void maxSumsubarray(int [],int );
int main(){
    cout<<"Enter array size:"<<endl;
    int n;
    cin>>n;

    cout<<"Enter array:"<<endl;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    maxSumsubarray(arr,n);
}
void maxSumsubarray(int arr[],int n){
    int maxSum = -1;
    int con[n],diff;
    con[0]=arr[0];
    for(int i=1;i<n;i++){
        diff= con[i-1]+arr[i];
        con[i]=max(diff,arr[i]);
        if(con[i]>maxSum){
            maxSum=con[i];
        }
    }
    cout<<"Maximum sum sub array is "<<maxSum<<endl;
}



