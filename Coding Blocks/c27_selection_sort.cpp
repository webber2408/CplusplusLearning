#include<iostream>
#include<vector>
#include<climits>
using namespace std;

/*
Idea Behind:

Start from the first index, find the minimum element in the array and replace it with the first one.
Now the smallest element is the first element of the array.
Similarly now do the same step for the array from [2..n]

*/
void selectionSort(vector<int> arr, int n){

    for(int i=0; i<n; i++){
        int swapIndex = -1, minVal = INT_MAX;
        for(int j=i; j<n; j++){
            if(arr[j] < minVal){
                minVal = arr[j];
                swapIndex = j;
            }
        }
        swap(arr[i], arr[swapIndex]);
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
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

