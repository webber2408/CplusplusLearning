#include<bits/stdc++.h>
using namespace std;
#define MAX 100
int fillArea(int [][MAX],int , int , int , int , int , int );
int main(){
    cout<<"Enter row and column size:"<<endl;
    int row,col;
    cin>>row;
    cin>>col;
    int color[row][MAX];
    cout<<"Enter color array :"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>color[i][j];
        }
    }
    cout<<"Entered array :"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<color[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Enter old color code to change:"<<endl;
    int old_color;
    cin>>old_color;
    cout<<"Enter new color code:"<<endl;
    int new_color;
    cin>>new_color;
    cout<<"Enter x-coordinate"<<endl;
    int i;
    cin>>i;
    cout<<"Enter y-coordinate:"<<endl;
    int j;
    cin>>j;
    fillArea(color, row , col , new_color , old_color , i-1 , j-1 );
    cout<<"Changed array :"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<color[i][j]<<" ";
        }
        cout<<endl;
    }

}
int fillArea(int color[][MAX],int row , int col , int new_color , int old_color , int i , int j){
    if(i>=row || j>=col || i<0 || j<0 || color[i][j] != old_color){
        return 0;
    }
    color[i][j] = new_color;
    fillArea(color,row,col,new_color,old_color,i+1,j);
    fillArea(color,row,col,new_color,old_color,i-1,j);
    fillArea(color,row,col,new_color,old_color,i,j+1);
    fillArea(color,row,col,new_color,old_color,i,j-1);
}
