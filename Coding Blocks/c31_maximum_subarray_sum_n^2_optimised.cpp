#include<iostream>
#include<climits>
using namespace std;

void printMaxSubArraySum(int arr[], int n, int cumSum[]){
    //Code goes here...
    int maxSum = INT_MIN, startIndex = 0, endIndex = 0;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            cout<<"Current Sum "<<cumSum[j]-cumSum[i-1]<<" i = "<<i<<" j = "<<j<<endl;
            if((cumSum[j]-cumSum[i-1])>maxSum){
                maxSum = cumSum[j]-cumSum[i-1];
                startIndex = i;
                endIndex = j;
            }
        }
    }
    cout<<"Max Sum: "<<maxSum<<endl;
    cout<<"Start Index: "<<startIndex<<endl;
    cout<<"End Index: "<<endIndex<<endl;

    return;
}

int main(){
    int N;
    cin>>N;

    int arr[N], cumSum[N] = {0};
    cout<<"Enter array: "<<endl;

    cin>>arr[0];
    cumSum[0] = arr[0];
    for(int i=1;i<N;i++){
        cin>>arr[i];
        cumSum[i] = cumSum[i-1]+arr[i];
    }

    printMaxSubArraySum(arr, N, cumSum);

    return 0;
}
