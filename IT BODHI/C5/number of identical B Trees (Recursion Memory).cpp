//time complexity: O(n^2)  because of loop and recursion( ek hi baar me pura nikal dega)
//space complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
int findSolution(int,int []);
int main(){
    cout<<"Enter number of nodes:"<<endl;
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0;i<=n;i++){
        arr[i] = -1;
    }
    arr[0]=1;
    arr[1]=1;
    int ans = findSolution(n,arr);
    cout<<"Total B Trees possible :"<<ans<<endl;
}
int findSolution(int n,int arr[]){
    int allcases,rc,lc;
    if(arr[n]>0){
        return arr[n];
    }
    allcases = 0;
    for(int i=0;i<=n-1;i++){

        rc=(arr[n-i-1]>0)?arr[n-i-1]:findSolution(n-i-1,arr);
        arr[n-i-1]=rc;
        lc = arr[i];
        allcases += rc*lc;
    }
    arr[n] = allcases;
    return arr[n];
}

