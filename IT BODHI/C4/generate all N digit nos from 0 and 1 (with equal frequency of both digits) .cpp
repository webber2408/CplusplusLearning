#include<bits/stdc++.h>
using namespace std;
void printArray(int [],int n);
void generateAllnos(int [],int , int , int , int );
int main(){
    cout<<"Enter number:"<<endl;
    int n;
    cin>>n;
    int arr[n];
    generateAllnos(arr,0,n,n/2,n/2);
}
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void generateAllnos(int arr[],int index,int sizeI , int zero_rem , int one_rem){

    if(index == sizeI){
        printArray(arr,sizeI);
        cout<<endl;
        return;
    }
    if(zero_rem>0){
    arr[index] = 0;
    generateAllnos(arr,index+1,sizeI,zero_rem-1,one_rem);
    }
    if(one_rem>0){
    arr[index] = 1;
    generateAllnos(arr,index+1,sizeI,zero_rem,one_rem-1);
    }
}

