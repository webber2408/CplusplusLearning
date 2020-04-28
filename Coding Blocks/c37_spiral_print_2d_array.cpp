#include<iostream>
using namespace std;

void spiralPrint(int arr[][1000], int m, int n){
    int startColumn = 0, startRow = 0, endColumn = n-1, endRow = m-1;

    while(startRow <= endRow && startColumn <= endColumn){

        //L-R Traversal
        for(int i = startColumn; i<= endColumn; ++i){
            cout<<arr[startRow][i]<<" ";
        }
        startRow++;

        //T-B Traversal
        for(int i = startRow; i <= endRow; ++i){
            cout<<arr[i][endColumn]<<" ";
        }
        endColumn--;

        //R-L Traversal
        if(startRow < endRow){
            for(int i = endColumn; i>= startColumn; --i){
                cout<<arr[endRow][i]<<" ";
            }
            endRow--;
        }

        //B-T Traversal
        if(startColumn < endColumn){
            for(int i = endRow; i>= startRow; --i){
                cout<<arr[i][startColumn]<<" ";
            }
            startColumn++;
        }
    }
}

int main(){

    int m, n;
    cin>>m>>n;

    int arr[1000][1000] = {0}, val = 1;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            arr[i][j] = val++;
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    spiralPrint(arr, m, n);

    return 0;
}