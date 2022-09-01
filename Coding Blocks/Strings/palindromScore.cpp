#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    int n, count=0;
    cin>>n;
    cin.get();
    string s[n];
    for(auto &st: s){
        getline(cin, st);
    }

    for(int i=0, j=n-1; i<n/2; i++, j--){
        if(s[i] != s[j]) count+=2;
    }
    
    cout<<count<<endl;

    return 0;    
}