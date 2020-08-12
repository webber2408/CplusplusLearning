#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

bool compare(string a, string b){
    return a.length()<b.length(); // Smallest first as using (<)
}

int main(){
    int n;
    cin>>n;
    cin.get();
    string s[n];
    for(auto &st: s){
        getline(cin, st);
    }
    // for(int i=0; i<n; i++){
    //     getline(cin, s[i]);
    // }
    sort(s, s+n, compare);

    for(auto &stemp: s){
        cout<<stemp<<endl;
    }

    return 0;    
}