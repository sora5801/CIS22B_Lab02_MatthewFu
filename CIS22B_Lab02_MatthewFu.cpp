#include <iostream>
#include <cstring>

using namespace std;

int stringLength(char* given_string);
void stringNCopy();
void stringNAdd();
void stringNCompare();



int main() {

   return 0;
}

int stringLength(char* given_string)
{

   int length = 0;
   while (*given_string != '\0') {
      length++;
      given_string++;
   }

   return length;
}