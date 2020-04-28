//time complexity O(m+n)
#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"Enter no of rows and no of columns :"<<endl;
    int p1,p2;
    cin>>p1;
    cin>>p2;
    int arr[p1][p2];
    cout<<"Enter 2D array values:"<<endl;
    for(int i=0;i<p1;i++){
        for(int j=0;j<p2;j++){
            cin>>arr[i][j];
        }
    }

    int nos = 0;
    int pos = 0;
    int x,y;
    x=0;
    y=0;
    while(x < p1){
        if(arr[x][y]==0){
            y++;
            if(y > nos){
                nos = y;
                pos = x;
            }
        }else{
            x++;
            y=0;
        }
    }
    cout<<"Found max zeros in line "<<pos+1<<" No of zeros = "<<nos<<endl;
}




