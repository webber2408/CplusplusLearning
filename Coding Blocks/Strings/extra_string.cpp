#include <iostream>
#include <cstring>
#include <string>

int main () {
   std::string str ("Please divide this sentance into parts");

   char * cstr = new char [str.length()+1];
   std::strcpy (cstr, str.c_str());

   char * p = std::strtok (cstr," ");
   while (p!=0) {
      std::cout << p << '\n';
      p = std::strtok(NULL," ");
   }

   delete[] cstr;
   return 0;
}