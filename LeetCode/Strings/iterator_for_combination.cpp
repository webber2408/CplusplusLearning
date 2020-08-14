/*
Design an Iterator class, which has:

A constructor that takes a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
A function next() that returns the next combination of length combinationLength in lexicographical order.
A function hasNext() that returns True if and only if there exists a next combination.

Example:

CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the iterator.

iterator.next(); // returns "ab"
iterator.hasNext(); // returns true
iterator.next(); // returns "ac"
iterator.hasNext(); // returns true
iterator.next(); // returns "bc"
iterator.hasNext(); // returns false
 

Constraints:

1 <= combinationLength <= characters.length <= 15
There will be at most 10^4 function calls per test.
It's guaranteed that all calls of the function next are valid.
*/
#include<bits/stdc++.h>
using namespace std;

bool myComparator(string s1, string s2){
    return s1 < s2; // lexographic sorting
}

class CombinationIterator{

    private:
        vector<string> subStrings;
        int it;

        void subStringHelper(char characters[], char tempString[], int i, int index, int combinationLength, int n){
            if(index == combinationLength){
                tempString[index] = '\0';
                this->subStrings.push_back(tempString);
                return;
            }
            if(i > n-1)
                return;
            tempString[index] = characters[i];
            subStringHelper(characters, tempString, i+1, index+1, combinationLength, n);
            subStringHelper(characters, tempString, i+1, index, combinationLength, n);
            return;
        }

        void getSubStringsOfGivenLength(string characters, int combinationLength){
            char tempString[100];
            subStringHelper((char *)characters.c_str(), tempString, 0, 0, combinationLength, characters.length());
            sort(subStrings.begin(), subStrings.end(), myComparator);
            // for(auto &temp: subStrings)
            //     cout<<temp<<endl;
            return;
        }

    public:
        CombinationIterator(string characters, int combinationLength){
            this->it = 0;
            getSubStringsOfGivenLength(characters, combinationLength);
        }

        string next(){
            string ans = this->subStrings[this->it];
            (this->it)++;
            return ans;
        }

        bool hasNext(){
            return (this->it < this->subStrings.size());
        }
};


int main(){
    CombinationIterator* ci = new CombinationIterator("abc", 2);
    string s1 = ci->next();
    cout<<s1<<endl;
    bool b1 = ci->hasNext();
    cout<<b1<<endl;
    s1 = ci->next();
    cout<<s1<<endl;
    b1 = ci->hasNext();
    cout<<b1<<endl;
    s1 = ci->next();
    cout<<s1<<endl;
    b1 = ci->hasNext();
    cout<<b1<<endl;
    return 0;
}