#include<bits/stdc++.h>
using namespace std;
#define MAX 100
void replaceSpaces(char [],int,char [],int);
int spaceCount = 0;
int main(){
    cout<<"Enter string:"<<endl;
    char str[MAX];
    gets(str);
    cout<<"Enter string you want to replace space with"<<endl;
    char rep[MAX];
    gets(rep);
    int len = strlen(str);
    int repLen = strlen(rep);
    replaceSpaces(str,len,rep,repLen);
    cout<<"Replaced String"<<endl;
    cout<<str;


}
void replaceSpaces(char str[] , int len , char rep[],int repLen){
    // counting number of spaces to define pointer positions
    for(int i=0;i<len;i++){
        if(str[i]==' '){
            spaceCount++;
        }
    }
    cout<<spaceCount<<endl;
    cout<<"len->"<<len<<endl;

    int wp = (spaceCount*repLen) + len - spaceCount;
    int rp = len;
    cout<<"wp->"<<wp<<endl;
    cout<<"rp->"<<rp<<endl;

    while(rp >= 0){
        if(str[rp] == ' '){
            int k = repLen-1;
            while(k>=0){
                str[wp] = rep[k];
                k--;
                wp--;
            }
        }else{
            str[wp] = str[rp];

            wp--;
        }
        rp--;
    }
}
