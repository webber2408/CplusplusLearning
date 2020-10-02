#include<iostream>
#include<cstring>
using namespace std;

// Using read and write pointers
void removeConsecutiveDuplicates(char* a){

    if(strlen(a) <= 1)
        return;
    
    int wp = 0, rp = 1;

    while(rp < strlen(a)){
        if(a[wp] == a[rp])
            rp++;
        else
            a[++wp] = a[rp++];
    }
    a[++wp] = '\0';
}

int main(){
    char a[1000];
    cin.getline(a, 1000);

    removeConsecutiveDuplicates(a);

    cout<<a<<endl;

    return 0;
}