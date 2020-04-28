#include<bits/stdc++.h>
using namespace std;
#define MAX 100
void reverseWord(char [] ,int );
void reverseIt(char [] , int , int );
int main(){
    cout<<"Enter string :"<<endl;
    char str[MAX];
    gets(str);
    int len = strlen(str);
    reverseWord(str,len);
    cout<<"Reversed string:"<<endl;
    puts(str);

}
void reverseWord(char str[],int len){
    reverseIt(str,0,len-1);
    int k = 0;
    for(int i=0;i<=len;i++){

        if(str[i]== ' ' || i== len){
            reverseIt(str,k,i-1);
           // cout<<"start->"<<k<<endl;
            //cout<<"end->"<<i-1<<endl;
            //puts(str);
            //cout<<endl;
            k = i+1;
        }
    }
}
void reverseIt(char str[],int l,int h){
    char temp;
    //cout<<"rec start->"<<l<<endl;
    //cout<<" rec end->"<<h<<endl;
    /*int mid=(h-l)/2;
    for(int i = 0 ; i<=mid;i++){
        temp = str[l+i];
        str[l+i] = str[h-i];
        str[h-i] = temp;

    }
    */
    int c = 0;
    for(int i = l ; i<=(l+h)/2;i++){
        temp = str[i];
        str[i] = str[h-c];
        str[h-c] = temp;
        c++;
    }
    puts(str);
    cout<<endl;
}
