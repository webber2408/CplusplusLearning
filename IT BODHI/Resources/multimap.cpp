#include<string.h>
#include<iostream>
#include<map>
#include<utility>
using namespace std;
multimap<string,string> m;
bool isNonTerminal(string s);
void calculateFirst(string s);
bool check(string s);
char nonterminals[3][10]={"SAM","ARR","BCC"};
pair<multimap<string,string>::iterator,multimap<string,string>::iterator> sub;
multimap<string,string> :: iterator itr;
int main(){

    m.insert(pair<string,string>("SAM","ARRBCC"));
    m.insert(pair<string,string>("SAM","SAMSAM"));
    m.insert(pair<string,string>("ARR","a"));
    m.insert(pair<string,string>("BCC","b"));


    for(itr = m.begin(); itr != m.end() ; ++itr){
        cout<<itr->first<<" -> "<<itr->second<<endl;
    }

    cout<<"More than one production of SAM"<<endl;

    sub=m.equal_range("SAM");
    for(itr = sub.first ; itr != sub.second ; ++itr){
        cout<<itr->first<<" -> "<<itr->second<<endl;
    }

    //code to calculate first
    cout<<"First SAM"<<endl;
    for(itr = sub.first ; itr != sub.second ; ++itr){
        calculateFirst(itr->second);
    }


    return 0;
}
bool isNonTerminal(string s){
        cout<<"here in nonterminal"<<endl;
        string temp;
        for(int j=0;s[j] != '\0';j++){
          temp += s[j];
          cout<<"new temp string formed"<<temp<<endl;
          if(check(temp))
            return true;
        }
    return false;
}
bool check(string s){
    cout<<"here in check"<<endl;
    for(int i=0;i<3;i++){
            cout<<s<<"=="<<nonterminals[i]<<endl;
        if(s == nonterminals[i])
        {
            cout<<s<<"=="<<nonterminals[i]<<endl;
            return true;
        }

    }
    return false;
}
void calculateFirst(string temp){
        if(isNonTerminal(temp)){
            calculateFirst(temp);
        }else{
            cout<<" -- "<<temp;
        }

}
