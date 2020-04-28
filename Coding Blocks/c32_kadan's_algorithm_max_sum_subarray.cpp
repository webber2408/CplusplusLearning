#include<iostream>
#include<climits>
using namespace std;

void printMaxSubArraySum(int arr[], int n){

    int max_so_far = INT_MIN, sum = 0, startIndex = 0, endIndex = 0, s = 0;

    for(int i =0;i<n;i++){
        sum += arr[i];
        if(sum>max_so_far){
            max_so_far = sum;
            startIndex = s;
            endIndex = i;
        }
        if(sum < 0){
            sum = 0;
            s = i+1;
        }
    }

    cout<<"Maximum Sum : "<<max_so_far<<endl;
    cout<<"Start Index: "<<startIndex<<endl;
    cout<<"End Index: "<<endIndex<<endl;
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
