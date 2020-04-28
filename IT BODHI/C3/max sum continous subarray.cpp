#include<bits/stdc++.h>
using namespace std;

void cummulative(int [],int [],int );
void maxSumsubarray(int [],int );
int main(){
    cout<<"Enter array size:"<<endl;
    int n;
    cin>>n;

    cout<<"Enter array:"<<endl;
    int arr[n];
    int cumu[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cummulative(arr,cumu,n);
    maxSumsubarray(cumu,n);
}
void cummulative(int arr[],int cumu[] , int n){
    cumu[0] = arr[0];
    for(int i=1;i<n;i++){
        cumu[i]=cumu[i-1]+arr[i];
    }
}
void maxSumsubarray(int cumu[],int n){
    int posX1 = 0 , posX2 = 0;
    int maxSum = -1,cuSum = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(i-1<0){
                cuSum = cumu[j];
            }else{
            cuSum = cumu[j]-cumu[i-1];
            }
            if(cuSum > maxSum){
                maxSum = cuSum;
                posX1=i;
                posX2= j;
            }
        }
    }

    cout<<"Maximum sum sub array is "<<maxSum<<" starting from "<<posX1<<" to "<<posX2<<endl;
}



