#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;
main() {
   int max;
   max = 100; //set the upper bound to generate the random number
   srand(time(0));
   vector<int> numbers(10);
   for(int i = 0; i<10; i++) { //generate 10 random numbers
      cout << "The random number is: "<<rand()%max << endl;
      numbers.push_back(rand()%max);
   }
   for(int i = 0;i < 10; i++){
       cout<<numbers[i]<<" ";
   }
}