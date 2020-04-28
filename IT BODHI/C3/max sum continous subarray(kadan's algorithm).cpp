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
    int maxSumsofar = 0;
    int cuSum = 0;
    int j=0,i=0;
    while(j<n){
        if(i==j){
            cuSum = arr[i];
        }
        else{
            cuSum = cuSum+arr[j];
            if(cuSum < 0){
                cuSum = 0;
                i=j+1;
            }
            if(cuSum > maxSumsofar){
                maxSumsofar = cuSum;
            }
        }
        j++;
    }
    cout<<"Maximum sum sub array is "<<maxSumsofar<<endl;
}




