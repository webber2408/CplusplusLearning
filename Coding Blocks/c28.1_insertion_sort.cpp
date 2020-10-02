#include<iostream>
#include<vector>
using namespace std;

/*
Idea behind: 
    The idea behind is similar to how we sort a deck of cards,
    Assume the first element as a one element sorted array.
    Start from the next element and try to place the element in the
    sorted array while maintaining the sorted nature.
*/

void insertionSort(vector<int> arr, int n){
    int j = 0, key = 0;
    for(int i=1; i<n; i++){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int N;
    cin>>N;

    vector<int> nums;
    int val;
    for(int i=0; i<N; i++){
        cin>>val;
        nums.push_back(val);
    }

    insertionSort(nums, N);

    return 0;
}