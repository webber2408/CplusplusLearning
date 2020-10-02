/*count the frequency of all the characters in this string.*/
#include<iostream>
using namespace std;

//O(26*s)
void countFrequency(string s){
    for(char ch = 'a'; ch <= 'z'; ch++){
        int frequency = 0;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == ch)
                frequency++;
        }
        cout<<ch<<" - "<<frequency<<endl;
    }
}

//O(s)
void countFrequencyUsingHashTable(string s){
    int HashTable[26] = {0};
    for(int  i=0; i<s.length(); i++){
        HashTable[s[i]-'a']++;
    }
    for(int i=0; i<26; i++){
        cout<<(char)(i+'a')<<" - "<<HashTable[i]<<endl;
    }
}

int main(){

    string s = "ababcd";

    //countFrequency(s);

    countFrequencyUsingHashTable(s);

    return 0;
}