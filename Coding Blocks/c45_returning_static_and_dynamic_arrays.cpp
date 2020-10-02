#include<bits/stdc++.h>
using namespace std;

//Returning Static Array Pointer
int * fun(){
    int a[] = {1,2,3,4,5};
    cout<<a<<endl; //Prints address of first element of array
    cout<<a[0]<<endl; //Prints 1

    //We should never return a local variable
    return a;
}

//Returning Dynamic Array Pointer
int * fun1(){
    int *a = new int[2];
    a[0] = 1;
    a[1] = 2;
    cout<<a<<endl; //Prints address of first element of array
    cout<<a[0]<<endl; //Prints 1

    return a;
}

int main(){

    // int *b = fun();
    // cout<<b<<endl; //Prints the copy of address of a;
    // cout<<b[0]<<endl; //Segmentation Fault: As the array definition in fun() was static and it was destroyed from the memory when the function, fun() exited!

    int *c = fun1();
    cout<<c<<endl;
    cout<<c[0]<<endl;

    //let us clear the dynamic array a which is now pointed by c
    //fun1 returned the array pointer before destroying all its local variables
    //this will not delete the int * c pointer
    //pointer c will be deleted when the mail function exits!
    delete [] c;
    c = 0; //reset c to null pointer //Good Practice

    return 0;
}