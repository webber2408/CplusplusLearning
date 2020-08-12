#include<iostream>
#include<string>
using namespace std;

int main(){
    string s0;

    string s1("hello");

    string s2 = "Hello World";

    string s3(s2); // Copy Constructor

    string s4 = s3; // Copying a string

    char a[] = {'a', 'b', 'c', '\0'};

    string s5(a);

    cout<<s0<<endl;
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s3<<endl;
    cout<<s4<<endl;
    cout<<s5<<endl;

    //Check empty
    if(s0.empty()){
        cout<<"s0 is an empty string!"<<endl;
    }

    //Append
    s0.append("Hey there!");
    s0 += ", how are you?";
    cout<<s0<<endl;

    //Remove/Erase Content of the String
    cout<<s0.length()<<endl;
    s0.clear();
    cout<<s0.length()<<endl;

    //Compare two strings
    s0 = "Apple";
    s1 = "Mango";
    cout<<s0.compare(s1)<<endl; // 0, >0, -1

    //Overloaded operatoe 
    if(s1 > s0){
        cout<<"Mango is lexically greater than apple!"<<endl;
    }

    // Access a character within a string
    cout<<s0[4]<<endl;

    //Find substrings
    s0 = "I want to have apple juice";
    int index = s0.find("apple");
    cout<<index<<endl;

    //Remove a word from the string
    string word = "apple";
    s0.erase(index, word.length()+1);
    cout<<s0<<endl;

    //Iterate over characters in a string
    for(int i=0; i<s0.length(); i++){
        cout<<s0[i]<<";";
    }
    cout<<endl;
    for(auto it=s0.begin(); it!=s0.end(); it++){
        cout<<*it<<";";
    }
    cout<<endl;
    for(string::iterator it=s0.begin(); it!=s0.end(); it++){
        cout<<*it<<";";
    }
    cout<<endl;

    //For each loop
    for(auto &ch: s0){
        cout<<ch<<":";
    }
    cout<<endl;
    for(auto c:s0){
        cout<<c<<".";
    }
    cout<<endl;


}