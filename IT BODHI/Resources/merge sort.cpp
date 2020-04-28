#include<bits/stdc++.h>
using namespace std;
void mergeSort(int [],int,int);
void mergeIt(int [],int,int,int);
void printArray(int [],int);
int main(){
    cout<<"Enter array size:"<<endl;
    int n;
    cin>>n;
    cout<<"Enter array :"<<endl;
    int arr[n];
    for(int i=0;i<=(n-1);i++){
        cin>>arr[i];
    }

    mergeSort(arr,0,n-1);
    printArray(arr,n);
}
void printArray(int a[],int n){
    cout<<"Sorted array :"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
}
void mergeSort(int a[],int l,int r){

    if(l<r){
    int m = l+(r-l)/2;
    //cout<<m<<endl;
    mergeSort(a,l,m);
    mergeSort(a,m+1,r);
    mergeIt(a,l,m,r);
    }

}
void mergeIt(int a[],int l,int m,int r){
  int h1 = m-l+1;
  int h2 = r-m;
  int temp1[h1];
  int temp2[h2];
  for(int i=0;i<h1;i++){
    temp1[i] = a[l+i];
  }
  for(int j=0;j<h2;j++){
    temp2[j] = a[m+1+j];
  }
  int j=0;
  int k=0;
  int p=l;

  while (j < h1 && k < h2)
    {
        if (temp1[j] <= temp2[k])
        {
            a[p] = temp1[j];
            j++;
        }
        else
        {
            a[p] = temp2[k];
            k++;
        }
        p++;
    }
  while(j< h1){
    a[p++] = temp1[j++];
  }
  while(k<h2){
    a[p++] = temp2[k++];
  }
}




