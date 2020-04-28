#include<bits/stdc++.h>
#include<stack>
using namespace std;
#define MAX 1000
void calcSupply(int [],int , stack <int> s);
int main(){
    stack <int> s;
    cout<<"Enter array size:"<<endl;
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter array :"<<endl;
    for(int i=0 ;i<=(n-1);i++){
        cin>>arr[i];
    }
    calcSupply(arr,n,s);
    return  0;
}

void calcSupply(int a[] , int n , stack <int> s ){
    s.push(a[0]);
    int b[n];
    b[0] = -1;
    for(int i = 1;i<n;i++){
        while(s.top() > a[i]){
            s.pop();
            if(s.empty()){
                break;
            }
        }
        if(s.empty()){
            b[i] = -1;
            s.push(a[i]);
        }else{
            b[i] = s.top();
            s.push(a[i]);
        }
    }

    for(int i =0;i<n;i++){
        cout<<b[i]<<endl;
    }
}
