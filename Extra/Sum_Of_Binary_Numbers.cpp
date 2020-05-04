#include<bits/stdc++.h>
using namespace std;

int main(){
    string a, b, ans;
    char c = '0';
    cout<<"Enter two binary strings"<<endl;
    cin>>a>>b;
    int i = a.length()-1;
    int j = b.length()-1;
    while(i >=0 && j >= 0){
        if(a[i] == '1' && b[j] == '0' && c == '1'){
            ans.push_back('0');
            c = '1';
        }else if(a[i] == '1' && b[j] == '0' && c == '0'){
            ans.push_back('1');
            c = '0';
        }else if(a[i] == '1' && b[j] == '1' && c == '1'){
            ans.push_back('1');
            c = '1';
        }else if(a[i] == '1' && b[j] == '1' && c == '0'){
            ans.push_back('0');
            c = '1';
        }else if(a[i] == '0' && b[j] == '1' && c == '1'){
            ans.push_back('0');
            c = '1';
        }else if(a[i] == '0' && b[j] == '1' && c == '0'){
            ans.push_back('1');
            c = '0';
        }else if(a[i] == '0' && b[j] == '0' && c == '1'){
            ans.push_back('1');
            c = '0';
        }else if(a[i] == '0' && b[j] == '0' && c == '0'){
            ans.push_back('0');
            c = '0';
        }
        i--;
        j--;
        a.pop_back();
        b.pop_back();
    }
    i = a.length()-1;
    while(i>=0){
        if(a[i] == '1' && c == '0'){
            ans.push_back('1');
            c = '0';
        }else if(a[i] == '1' && c == '1'){
            ans.push_back('0');
            c = '1';
        }else if(a[i] == '0' && c == '0'){
            ans.push_back('0');
            c = '0';
        }else if(a[i] == '0' && c == '1'){
            ans.push_back('1');
            c = '0';
        }
        i--;
    }
    i = b.length()-1;
    while(i>=0){
        if(b[i] == '1' && c == '0'){
            ans.push_back('1');
            c = '0';
        }else if(b[i] == '1' && c == '1'){
            ans.push_back('0');
            c = '1';
        }else if(b[i] == '0' && c == '0'){
            ans.push_back('0');
            c = '0';
        }else if(b[i] == '0' && c == '1'){
            ans.push_back('1');
            c = '0';
        }
        i--;
    }
    if(c == '1')
        ans.push_back(c);
    int l = 0;
    int r = ans.length()-1;
    while(l<r){
        swap(ans[l], ans[r]);
        l++;
        r--;
    }

    cout<<"Answer : "<<ans<<endl;

    return 0;
}