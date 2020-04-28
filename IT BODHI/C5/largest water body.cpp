// amortized cost as calculated only when encountered zero that too only once so O(m x n)
//space O(m x n)
#include<bits/stdc++.h>
using namespace std;
#define MAX 100
int driver(int [][MAX],int ,int);
int getWaterbodysize(int [][MAX],int , int , int , int );
int main(){
    cout<<"Enter array row and column:"<<endl;
    int row;
    int col;
    cin>>row;
    cin>>col;
    cout<<"Enter array:"<<endl;
    int body[row][MAX];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>body[i][j];
        }
    }
    cout<<"Entered array:"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<body[i][j]<<" ";
        }
        cout<<endl;
    }
    int largestWaterbody = driver(body,row,col);
    cout<<"Largest water body size = "<<largestWaterbody<<endl;
}
int driver(int body[][MAX],int row , int col){
    int waterSize = 0;
    int maxSize = -1;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
        {
            if(body[i][j] == 0){
                waterSize = getWaterbodysize(body,i,j,row,col);
            }
            if(waterSize >= maxSize){
                maxSize = waterSize;
            }
        }
    }
    return maxSize;
}
int getWaterbodysize(int body[][MAX],int i , int j , int row , int col){
    if(i<0 || i>=row || j<0 || j>= col || body[i][j] != 0){
        return 0;
    }
    body[i][j] = -1;
    return 1+getWaterbodysize(body,i+1,j,row,col)+getWaterbodysize(body,i-1,j,row,col)+
    getWaterbodysize(body,i,j+1,row,col)+
    getWaterbodysize(body,i,j-1,row,col);
}


