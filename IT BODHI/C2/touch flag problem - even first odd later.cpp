#include<bits/stdc++.h>
using namespace std;
void solveProblem(int [],int);
void swapIt(int * , int *);
int main(){
    cout<<"Enter array size:"<<endl;
    int n;
    cin>>n;
    cout<<"Enter array:"<<endl;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    solveProblem(arr,n);
    cout<<"Array after even first and odd later:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}
void swapIt(int *p1 , int *p2){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
void solveProblem(int arr[],int n){
    int wp = 0;
    for(int i=0;i<n;i++){
        if(arr[i]%2 == 0){
            swapIt(&arr[i],&arr[wp]);
            wp++;
        }
    }
}
