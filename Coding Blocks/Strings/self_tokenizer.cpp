#include<iostream>
#include<cstring>
using namespace std;

char* mystrtok(char *s, char delim){
    static char*input = NULL; //set only once!

    if(s != NULL){
        input = s;
    }
    //base case -> after the final token has been extracted!
    if(input == NULL){
        return NULL;
    }

    //start extracting tokens and store them in a dynamic array.
    char* output = new char[strlen(input) + 1];
    int i=0;
    for(; input[i] != '\0'; i++){
        if(input[i] != delim){
            output[i] = input[i];
        }else{
            output[i] = '\0';
            input = input + i + 1; // 1 is for space
            return output;
        }
    }

    //corner case (last)
    output[i] = '\0';
    input = NULL;
    return output;
}

int main(){
    char s[100] = "May you have, a great day today";

    char* ptr = mystrtok(s, ' ');
    cout<<ptr<<endl;

    while(ptr!=NULL){
        ptr = mystrtok(NULL, ' ');
        cout<<ptr<<endl;
    }

    return 0;
}