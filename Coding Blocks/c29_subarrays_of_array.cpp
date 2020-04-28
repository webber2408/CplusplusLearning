#include<iostream>
using namespace std;

void printSubArrays(int arr[], int n){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i; k<=j; k++){
                cout<<arr[k]<<" ";
            }
            cout<<endl;
        }
    }
}
int main(){
    int N;
    cin>>N;

    int arr[N];
    cout<<"Enter array: "<<endl;

    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    printSubArrays(arr, N);

    return 0;
}
