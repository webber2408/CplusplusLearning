#include<iostream>
using namespace std;

void readLine(char a[], int maxLength){
    int i=0;
    char ch = cin.get();
    while(ch != '\n'){
        a[i++] = ch;
        if(i == maxLength-2)
            break;
        ch = cin.get();
    }
    a[i] = '\0';

    cout<<a<<endl; // hello world
}

int main(){

    char a[1000];

    // 1
    // cin>>a;
    // cout<<a<<endl; // doesn't accept spaces!

    // 2
    // readLine(a, 1000);

    //3
    cin.getline(a, 1000, '$');
    cout<<a<<endl;
    

    return 0;
}