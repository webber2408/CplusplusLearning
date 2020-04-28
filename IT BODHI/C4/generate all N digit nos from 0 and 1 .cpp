#include<bits/stdc++.h>
using namespace std;
void printArray(int [],int n);
void generateAllnos(int [],int , int);
int main(){
    cout<<"Enter number:"<<endl;
    int n;
    cin>>n;
    int arr[n];
    generateAllnos(arr,0,n);
}
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void generateAllnos(int arr[],int index,int sizeI){

    if(index == sizeI){
        printArray(arr,sizeI);
        cout<<endl;
        return;
    }
    arr[index] = 0;
    generateAllnos(arr,index+1,sizeI);
    arr[index] = 1;
    generateAllnos(arr,index+1,sizeI);

}
