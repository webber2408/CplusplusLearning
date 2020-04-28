#include<iostream>
#include<algorithm>
using namespace std;


void printArray(int arr[1000][1000], int m, int n){
    cout<<"Output"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void printRotatedArrayBy90(int arr[1000][1000], int m, int n){
    cout<<"90 Degrees Rotated Array"<<endl;
    for(int j=0;j<n;j++){
        for(int i=m-1;i>=0;i--){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
}

void rotate(int arr[1000][1000], int m, int n){
    //Reverse
    for(int i=0;i<m;i++){
        int start = 0;
        int end = n-1;
        while(start<end){
            arr[i][end] = arr[i][start] + arr[i][end];
            arr[i][start] = arr[i][end] - arr[i][start];
            arr[i][end] = arr[i][end] - arr[i][start];
            start++;
            end--;
        }
    }

    printArray(arr, m, n);


    //Transpose
    for(int j=0;j<n;j++){
        for(int i=j+1;i<m;i++){
            swap(arr[i][j], arr[j][i]);
        }
    }

    cout<<"Rotated Array"<<endl;
    printArray(arr, m, n);
}

void rotateSTL(int arr[1000][1000], int m, int n){

    //Reverse using STL
    for(int i=0;i<m;i++){
        reverse(arr[i], arr[i]+n);
    }

    printArray(arr, m, n);

    //Transpose
    for(int j=0;j<n;j++){
        for(int i=j+1;i<m;i++){
            swap(arr[i][j], arr[j][i]);
        }
    }

    cout<<"Rotated Array"<<endl;
    printArray(arr, m, n);
}

int main(){
    int m, n, val = 1;
    cin>>m>>n;

    int arr[1000][1000] = {0};

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            arr[i][j] = val++;
        }
    }

    cout<<"Input Array"<<endl;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    // printRotatedArrayBy90(arr, m, n);

    //rotate(arr, m, n);

    rotateSTL(arr, m, n);
    return 0;
    
}