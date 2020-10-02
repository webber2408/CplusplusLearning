/*
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/
#include<bits/stdc++.h>
using namespace std;

string getMinimumNumber(string s, int k){
    if(k >= s.length())
        return "0";
    if(k==0)
        return s;
    
    stack<char> charStack;

    charStack.push(s[0]);
    for(int i=1;i<s.length();i++){
        while(k>0){
            if(!charStack.empty() && charStack.top() > s[i]){
                charStack.pop();
                k--;
            }else{
                break;
            }
        }
        charStack.push(s[i]);
    }

    while(k>0){
        charStack.pop();
        k--;
    }

    string result = "";
    while(!charStack.empty()){
        result.push_back(charStack.top());
        charStack.pop();
    }

    reverse(result.begin(), result.end());

    int size = result.size();
    for(int i=0;i<result.size();i++){
        if(result[i] == '0'){
            result.erase(i,1);
            i--;
        }else{
            break;
        }
    }

    if(result.compare("") == 0){
        return "0";
    }
    return result;
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    string s;
    cin>>s;
    int k;
    cin>>k;
    string ans = getMinimumNumber(s,k);
    cout<<ans;

    return 0;
}