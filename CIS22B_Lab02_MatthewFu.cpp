#include <iostream>
#include <cstring>

using namespace std;

int stringLength(char* given_string);
void stringNCopy(char str1[], char str2[], int num);
void stringNAdd(char str3[], char str4[], int num2);
void stringNCompare(char str5, char str6[], int num3);



int main() {
   cout << "We have 4 string functions to test.\n\n\n.";
   cout << "Input L if you want to test out the stringLength function, C if you want to test out stringNCopy" <<
      "A if you want to test out the stringNAdd function, and M if you want to test out the stringNCompare function" << endl;
   char again;
   do {
      char userInput;
      if (userInput == 'L') {}
      else if (userInput == 'C') {}
      else if (userInput == 'A') {}
      else if (userInput == 'M') {}
      else {
         cout << "Invalid Input \n";
      }

      cout << "Would you like to run the program again? (Y/N): " << endl;
      cin >> again;
   } while (again == 'y' || again == 'Y');
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

void stringNCopy(char str1[], char str2[], int num) {
   int index = 0;
   while ((str2[index] != '\0') && index < num)
   {
      str1[index] = str2[index];
      index++;
   }
   str1[num] = '\0';
}

void stringNAdd(char str3[], char str4[], int num2) {
   int index = 0;
   int lengthOfString = 0;

   while (str3[index] != '\0') {
      index++;
      lengthOfString++;
   }

   for (int i = 0; i < num2; i++)
   {
      str3[lengthOfString + i] = str4[i];
      if (str4[i] == '\0') break;
   }
}

void stringNCompare(char str5, char str6[], int num3) {
}