#include<iostream>
using namespace std;

void staircaseSearch(int arr[1000][1000], int m, int n, int k){
    int x = 0, y = n-1;
    bool found = false;
    while(x < m && y < n){
        if(arr[x][y] < k){
            x++;
        }else if(arr[x][y] > k){
            y--;
        }else{
            cout<<"Found at ("<<x+1<<","<<y+1<<") ";
            found = true;
            break;
        }
    }
    if(!found)
        cout<<"Element not present in the supplied array"<<endl;
    return;
}

int main(){
    int n,m,k;
    cin>>n>>m;
    int arr[1000][1000];
    cout<<"Enter row and column wise sorted array"<<endl;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    cout<<"Enter k"<<endl;
    cin>>k;

    cout<<"Input Array"<<endl;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    staircaseSearch(arr, m, n, k);

    return 0;
}