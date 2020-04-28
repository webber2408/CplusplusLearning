#include <iostream>

int getSum(int a, int b){
    return a+b;
}
int main(){
    int a = 0, b = 0;
    std::cin>>a;
    std::cin>>b;
    
    std::cout<<getSum(a, b);
}