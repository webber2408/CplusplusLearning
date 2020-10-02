#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<algorithm>
using namespace std;

long long getMaxProduct(const vector<long long> &, int);
long long getMaxProduct2(const vector<int> &, int);
int getMax(int a, int b);
int main(){

    // std::srand(time(0));
    // while(true){
    //     int n = std::rand() % 4 + 2;
    //     cout<<n<<"\n";
    //     vector<int> numbers(n);
    //     std::generate(numbers.begin(), numbers.end(), []() {
    //         return rand() % 10;
    //     });
 
    //     for(int i = 0; i<n; i++){
    //         cout<<numbers[i]<<" ";
    //     }
    //     cout<<"\n";
    //     long long product = getMaxProduct(numbers,n);
    //     long long product2 = getMaxProduct2(numbers,n);
    //     if(product != product2){
    //         cout<<"Wrong Answer"<<product<<" "<<product2<<"\n";
    //         break;
    //     }else{
    //         cout<<"OK"<<"\n";
    //     }
    // }
    int n;
    cin>>n;
    vector<long long> numbers(n);
    for(int i = 0; i<n; i++){
        cin>>numbers[i];
    }
    long long product = getMaxProduct(numbers, n);
    cout<<product<<"\n";
    return 0;
}

long long getMaxProduct(const vector<long long> &numbers, int n){
    int a = numbers[0], b = numbers[1];
    for(int i = 2; i< n; i++){
        if(numbers[i]< a && numbers[i] < b) continue;
        else if(numbers[i] >= a && numbers[i] < b) a = numbers[i];
        else if(numbers[i] < a && numbers[i] >= b) b = numbers[i];
        else if(abs(numbers[i]-a) > abs(numbers[i] - b)) a = numbers[i];
        else b = numbers[i];
    }
    // cout<<a<<b;
    return (long long)a*b;
}

long long getMaxProduct2(const vector<int> & numbers, int n){
    int max = 0;
    for(int i = 0; i< n; i++){
        for(int j = i+1; j<n; j++){
            max = getMax(max, numbers[i]*numbers[j]);
        }
    }
    return max;
}

int getMax(int a, int b){
    if(a > b) return a;
    else if(b > a) return b;
    return a;
}