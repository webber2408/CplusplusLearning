#include<iostream>
#include<vector>
using namespace std;

/*

Idea behind:
    Like bubbles in a water, heavier ones move upward and burst, 
    similarly try to move the heavier/greater items in the array to the end.

    We have to do it for the number of elements in the array times,
    because each time we move the largest element to the end of the
    array.
*/
void bubbleSort(vector<int> arr, int n){

    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){ 
            //Each time pick the largest element and push to end
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
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

    bubbleSort(unsorted_array, n);
}