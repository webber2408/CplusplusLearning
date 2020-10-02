/*
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> hashMap;
        int ans = 0;
        for(auto &ch: s){
            if(hashMap.find(ch) == hashMap.end())
                    hashMap[ch] = 1;
            else{
                hashMap[ch]++;
                // below step can be optimised with erase()
                if(hashMap[ch] == 2){
                    ans += 2;
                    hashMap[ch] = 0;
                }
            }
        }

        // this can be made a single line
        for(auto &pair: hashMap){
            if(pair.second == 1){
                ans += 1; 
                break;   
            }
        }
        return ans;
    }
};