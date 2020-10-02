#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 0)
            return true;
        stack <char> k;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                k.push(s[i]);
            }else{
                cout<<k.top();
                if(s[i] == '}'){
                    if(k.top() == '{'){
                        k.pop();
                    }else{
                        return false;
                    }
                }
                if(s[i] == ']'){
                    if(k.top() == '['){
                        k.pop();
                    }else{
                        return false;
                    }
                }
                if(s[i] == ')'){
                    if(k.top() == '('){
                        k.pop();
                    }else{
                        return false;
                    }
                }
            }
        }
        if(k.size() == 0){
            return true;
        }
        return false;
    }
};

int main(){
    Solution s1;
    cout<<s1.isValid("[]");
    return 0;
}