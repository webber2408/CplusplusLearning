#include<bits/stdc++.h>
using namespace std;

int main(){


    int **arr;
    int r, c;
    cin>>r>>c;
    arr = new int * [r];
    for(int i=0;i<r;i++){
        arr[i] = new int [c];
    }
    //Initialisation of 2D Array -> arr complete;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>arr[i][j];
        }
    }

    //Print
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}