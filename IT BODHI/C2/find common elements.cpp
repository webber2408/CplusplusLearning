#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
void mergeSort(int [],int,int);
void mergeIt(int [],int,int,int);
void printArray(int [],int);
int counter=0;
int main(){
    cout<<"Enter array1 size:"<<endl;
    int n1;
    cin>>n1;
    cout<<"Enter array :"<<endl;
    int arr1[n1];
    for(int i=0;i<=(n1-1);i++){
        cin>>arr1[i];
    }
    int same[n1];
    for(int j=0;j<n1;j++){
        same[j] = 0;
    }
    cout<<"Enter array2 size:"<<endl;
    int n2;
    cin>>n2;
    cout<<"Enter array2 :"<<endl;
    int arr2[n2];
    for(int i=0;i<=(n2-1);i++){
        cin>>arr2[i];
    }

    mergeSort(arr2,0,n2-1);
    printArray(arr2,n2);
    int j=0;
    for(int i=0;i<n1;i++){
        if(binary_search(arr2,arr2+n2,arr1[i])){
            counter++;
            same[j++] = arr1[i];
        }
    }
    cout<<"Common elements are :"<<endl;
    for(int j=0;j<n1;j++){
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





