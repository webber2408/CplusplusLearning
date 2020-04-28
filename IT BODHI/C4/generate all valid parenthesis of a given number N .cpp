#include<bits/stdc++.h>
using namespace std;
void printArray(char [],int n);
void generateAllnos(char [],int , int , int  ,int );
int main(){
    cout<<"Enter number:"<<endl;
    int n;
    cin>>n;
    char arr[n];
    generateAllnos(arr,0,n,0,0);
}
void printArray(char arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void generateAllnos(char arr[],int index,int sizeI , int left_surp , int left_count){
    if(index == sizeI){
        printArray(arr,sizeI);
        cout<<endl;
        return;
    }
    if(left_count<sizeI/2){
    arr[index] = '(';
    generateAllnos(arr,index+1,sizeI,left_surp+1,left_count+1);
    }
    if(left_surp>0){
    arr[index] = ')';
    generateAllnos(arr,index+1,sizeI,left_surp-1,left_count);
    }
}


