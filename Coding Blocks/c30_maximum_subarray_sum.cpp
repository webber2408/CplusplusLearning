#include<iostream>
#include<climits>
using namespace std;

void printMaxSubArraySum(int arr[], int n){
    int maxSum = INT_MIN, sum=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            sum = 0;
            for(int k=i; k<=j; k++){
                sum+= arr[k];
            }
            if(sum>maxSum){
                maxSum = sum;
            }
        }
    }

    cout<<"Maximum Sum : "<<maxSum<<endl;
}
int main(){
    int N;
    cin>>N;

    int arr[N];
    cout<<"Enter array: "<<endl;

    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    printMaxSubArraySum(arr, N);

    return 0;
}
