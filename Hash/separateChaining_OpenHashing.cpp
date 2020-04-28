#include<iostream>
#include<vector>
using namespace std;

//Here out hash table is an array of vectors
vector <string> HashTable[12];

int hashFunc(string s){
    int sum = 0;
    for(int i=0; i<s.length();i++){
        sum+= s[i];
    }
    return sum%11;
}

void insert(string s){
    int index = hashFunc(s);
    HashTable[index].push_back(s);
}

void search(string s){
    int index = hashFunc(s);
    
    for(int i=0;i<HashTable[index].size();i++){
        if(HashTable[index][i] == s){
            cout<< s <<" is found at "<<index<<endl;
            return;
        }
    }

    cout<<s<<" is not found"<<endl;
}

void printHashTable(){
    for(int i=0;i<12;i++){
        cout<<i<<" := ";
        for(int j=0;j<HashTable[i].size();j++){
            cout<<HashTable[i][j]<<" -> ";
        }
        cout<<endl;
    }
}

int main(){
    string strings[10] = {"Rahul", "Hulra", "Sharma", "Mohan", "Mishra", "Patel", "Keshav"};

    for(int i=0;i<7;i++){
        insert(strings[i]);
    }

    printHashTable();

    search("Keshav");

    return 0;
}