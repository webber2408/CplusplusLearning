#include<bits/stdc++.h>
using namespace std;
#define MAX 100
void mergeIt(int [],int [],int,int);
int counter=0;
int n1;
int same[MAX];
int main(){
    cout<<"Enter sorted array1 size:"<<endl;

    cin>>n1;
    cout<<"Enter sorted array1 :"<<endl;
    int arr1[n1];
    for(int i=0;i<=(n1-1);i++){
        cin>>arr1[i];
    }

    for(int j=0;j<MAX;j++){
        same[j] = 0;
    }

    cout<<"Enter sorted array2 size:"<<endl;
    int n2;
    cin>>n2;
    cout<<"Enter sorted array2 :"<<endl;
    int arr2[n2];
    for(int i=0;i<=(n2-1);i++){
        cin>>arr2[i];
    }

    mergeIt(arr1,arr2,n1,n2);


    cout<<"Common elements are :"<<endl;
    for(int j=0;j<counter;j++){
        if(same[j] != 0){
        cout<<same[j]<<"->";
        }
    }
}

void printArray(int a[],int n){
    cout<<"Sorted array2 :"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
}

void mergeIt(int arr1[],int arr2[] , int n1,int n2){

  int j=0;
  int k=0;
  int p=0;

  while (j < n1 && k < n2)
    {
        if (arr1[j] < arr2[k])
        {
            //same[p] = arr1[j];
            j++;
        }
        else if(arr2[k] < arr1[j])
        {
            //same[p] = arr2[k];
            k++;
        }else{
            counter++;
            same[p++] = arr1[j];
            j++;
            k++;
        }

    }

}





