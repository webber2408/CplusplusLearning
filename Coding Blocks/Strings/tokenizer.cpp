#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char s[100] = "May you have a nice day!";

    char* ptr = strtok(s, " "); //creates an array of tokens
    cout<<ptr<<endl; //ptr points to the first token in the given string //May

    // // Getting the next token
    // ptr = strtok(NULL, " ");
    // cout<<ptr<<endl; //you

    //Print all tokens
    while(ptr!=NULL){
        ptr = strtok(NULL, " ");
        cout<<ptr<<endl;
    }

    return 0;
}