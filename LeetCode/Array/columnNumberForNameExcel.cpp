#include<iostream>
#include<cmath>
using namespace std;

int main(){
    string s;
    cin>>s;
    int power = 0, result = 0;
    for(int i=s.length()-1; i>=0; i--){
        int charValue = s[i] - 'A' + 1;
        result += charValue*pow(26, power++);
    }
    cout<<result<<endl;
    return 0;    
}