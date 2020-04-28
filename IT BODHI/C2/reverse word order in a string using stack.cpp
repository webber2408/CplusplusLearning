#include<bits/stdc++.h>
#include<stack>
using namespace std;
#define MAX 100
stack <char> s;
char reverseStr[MAX];
void reverseWord(char [] ,int );
int main(){
    cout<<"Enter string :"<<endl;
    char str[MAX];
    gets(str);
    int len = strlen(str);
    reverseWord(str,len);

    cout<<"Reversed string:"<<endl;
    puts(reverseStr);
}
void reverseWord(char str[],int len){
    int k=0;
    for(int i=len-1;i >= 0 ; i--){
        if(str[i] != ' '){
            s.push(str[i]);
        }else{
            while(!s.empty()){
                reverseStr[k++]=s.top();
                s.pop();
            }
            reverseStr[k++]=' ';
        }
        if(i == 0){
            while(!s.empty()){
                reverseStr[k++]=s.top();
                s.pop();
            }
            reverseStr[k] = '\0';
        }
    }
}
