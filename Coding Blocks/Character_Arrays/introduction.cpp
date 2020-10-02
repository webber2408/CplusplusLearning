#include<iostream>
using namespace std;

int main(){

    char a[] = {'a', 'b', 'c', '\0'};
    cout<<a<<endl; //abc (Special Case)

    char str[5]; //Need to specify the size here!
    cin>>str;
    cout<<str<<endl;

    char s[] = "hello"; // Terminates with a null
    char s1[] = {'h', 'e', 'l', 'l', 'o'}; // Prints until it encounter a null character
    //Hence it is important to terminate each string with a null character.
    cout<<s<<" "<<sizeof(s)<<endl; //  incorporates null character (o/p: hello 6)
    cout<<s1<<" "<<sizeof(s1)<<endl; // (o/p: hello[hello->Garbage] 5)


    return 0;
}