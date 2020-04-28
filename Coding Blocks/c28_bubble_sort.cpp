#include<iostream>
#include<vector>
using namespace std;

bool compare(int a, int b){
    return a>b;
}

void bubbleSort(vector<int> arr, int n, bool (&cmp)(int a, int b)){

    for(int i = 0;i < n;i++){
        for(int j = 0;j< n-i-1;j++){
            if(cmp(arr[j], arr[j+1])){
                swap(arr[j+1], arr[j]);
            }
        }
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

    bubbleSort(unsorted_array, n, compare);
}