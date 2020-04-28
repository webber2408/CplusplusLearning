#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int> arr, int n){
    
    int i=0;
    while(i<n-1){
        int j = i, minIndex = i;
        while(j <= n-1){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
            j++;
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
        i++;
    }

    cout<<"Sorted Array"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    cout<<"Enter unsorted array"<<endl;
    vector<int> unsorted_array;

    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        unsorted_array.push_back(num);
    }

    selectionSort(unsorted_array, n);
}