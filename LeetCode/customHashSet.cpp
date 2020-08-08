#include<iostream>
#include<vector>
using namespace std;



int main(){
    MyHashSet* obj = new MyHashSet();
    obj->add(1);
    obj->add(2);
    obj->remove(1);
    cout<<obj->contains(1)<<endl;
    cout<<obj->contains(2)<<endl;

    return 0;
}