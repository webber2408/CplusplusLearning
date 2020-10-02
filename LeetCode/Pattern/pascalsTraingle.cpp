#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n][n];

    arr[0][0] = 1;
    arr[1][0] = 1;
    arr[1][1] = 1;
    cout<<1<<endl;
    cout<<1<<" "<<1<<endl;
    for(int i=2; i<n; ++i){
        arr[i][0] = 1;
        cout<<arr[i][0]<<" ";
        int j = 1;
        while(j < i){
            arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
            cout<<arr[i][j]<<" ";
            j++;
        }
        arr[i][i] = 1;
        cout<<arr[i][i]<<endl;
    }

    return 0;
}