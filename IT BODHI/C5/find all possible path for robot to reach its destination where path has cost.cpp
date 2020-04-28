// time complexity : O(2 ^ [n+m-1])
// space complexity : O(n+m)
#include<bits/stdc++.h>
using namespace std;
#define MAX 100
int findPath(int [][MAX],int,int);
int main(){
    cout<<"Enter row and column:"<<endl;
    int row,col;
    cin>>row;
    cin>>col;
    cout<<"Enter cost array:"<<endl;
    int arr[row][MAX];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }
    int ans = findPath(arr,row-1,col-1);
    cout<<"Least possible cost = "<<ans;
}
int findPath(int arr[][MAX],int i,int j){
    if(i < 0 || j < 0){
        return INT_MAX;
    }
    if(i == 0 && j == 0){
        return arr[i][j];
    }
    return min(findPath(arr,i-1,j),findPath(arr,i,j-1))+arr[i][j];
}

