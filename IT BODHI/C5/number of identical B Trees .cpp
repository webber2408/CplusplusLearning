//time complexity: O(n^n)
//space complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
int findSolution(int);
int main(){
    cout<<"Enter number of nodes:"<<endl;
    int n;
    cin>>n;
    int ans = findSolution(n);
    cout<<"Total B Trees possible :"<<ans<<endl;
}
int findSolution(int n){
    int allcases;
    if(n==0||n==1){
        return 1;
    }
    allcases = 0;
    for(int i=0;i<=n-1;i++){
        allcases = allcases+(findSolution(i)*findSolution(n-i-1));
    }
    return allcases;
}
