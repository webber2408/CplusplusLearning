// time complexity : O(2 ^ [n+m-1])
// space complexity : O(n+m)
#include<bits/stdc++.h>
using namespace std;
int findPath(int,int);
int main(){
    cout<<"Enter row and column:"<<endl;
    int row,col;
    cin>>row;
    cin>>col;
    int ans = findPath(row-1,col-1);
    cout<<"All possible paths count = "<<ans;
}
int findPath(int i,int j){
    if(i < 0 || j < 0){
        return 0;
    }
    if(i == 0 && j == 0){
        return 1;
    }
    return findPath(i-1,j)+findPath(i,j-1);
}
