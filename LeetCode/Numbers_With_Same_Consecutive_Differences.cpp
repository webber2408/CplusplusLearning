/*
Return all non-negative integers of length N such that the absolute difference between every two consecutive digits is K.

Note that every number in the answer must not have leading zeros except for the number 0 itself. For example, 01 has one leading zero and is invalid, but 0 is valid.

You may return the answer in any order.

 

Example 1:

Input: N = 3, K = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
Example 2:

Input: N = 2, K = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
 

Note:

1 <= N <= 9
0 <= K <= 9
*/
#include<bits/stdc++.h>
using namespace std;

void dfs(int N, int K, int curr, int index, int prev, vector<int> &ans){
    if(index == N-1){
        ans.push_back(curr);
        return;
    }
    int next = prev + K;
    if(next < 10)
        dfs(N, K, (curr*10)+next, index+1, next, ans);
    next = prev - K;
    if(K != 0 && next >= 0)
    dfs(N, K, (curr*10)+next, index+1, next, ans);
    return;
}

vector<int> numsSameConsecDiff(int N, int K) {
    vector<int> ans;
    if(N==1){
        for(int i=0; i<=9; i++)
            ans.push_back(i);
        return ans;
    }

    for(int i=1; i<=9; i++){
        dfs(N, K, i, 0, i, ans);
    }
    sort(ans.begin(), ans.end());
    return ans;
}



int main(){

    int n, k;
    cin>>n>>k;

    vector<int> ans = numsSameConsecDiff(n, k);

    for(auto it: ans)
        cout<<it<<" ";
    cout<<endl;

    return 0;
}



