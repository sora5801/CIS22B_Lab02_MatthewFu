#include <iostream>
#include <cstring>

using namespace std;

int stringLength(char* given_string);
void stringNCopy(char str1[], char str2[], int num);
void stringNAdd(char str3[], char str4[], int num2);
int stringNCompare(char *str5, char *str6, int num3);



int main() {
   const int SIZE = 100;
   
   cout << "We have 4 string functions to test.\n\n\n";
   cout << "Input L if you want to test out the stringLength function, C if you want to test out stringNCopy" <<
      "A if you want to test out the stringNAdd function, and M if you want to test out the stringNCompare function" << endl;
   char again;
   do {
      char line[SIZE];
      char line2[SIZE];
      char userInput;
      int number;
      cin >> userInput;
      if (userInput == 'L') {
         cout << "Enter a sentence of no more than "
            << (SIZE - 1) << " characters:\n";
         cin.ignore();
         cin.getline (line, SIZE); 
         cout << stringLength(line) << endl;
      }
      else if (userInput == 'C') {
         cout << "Enter a sentence of no more than "
            << (SIZE - 1) << " characters:\n";
         cin.ignore();
         cin.getline(line, SIZE);
         cout << "Enter a number less than " << SIZE << endl;
         cin >> number;
         stringNCopy(line2, line, number);
         cout << line2  << endl;
      }
      else if (userInput == 'A') {
         cout << "Enter a sentence of no more than "
            << (SIZE - 1) << " characters:\n";
         cin.ignore();
         cin.getline(line, SIZE);
         
         cout << "Enter another sentence of no more than "
            << (SIZE - 1) << " characters:\n";
       
         cin.getline(line2, SIZE);
         
         cout << "Enter a number less than " << SIZE << endl;
         cin >> number;
          stringNAdd(line, line2, number);
          cout << line <<endl;
         
         
      }
      else if (userInput == 'M') {
         cout << "Enter a sentence of no more than "
            << (SIZE - 1) << " characters:\n";
         cin.ignore();
         cin.getline(line, SIZE);
         cout << "Enter another sentence of no more than "
            << (SIZE - 1) << " characters:\n";
         cin.ignore();
         cin.getline(line2, SIZE);
         cout << "Enter a number less than " << SIZE << endl;
         cin >> number;
         cout << stringNCompare(line, line2, number) <<endl;
      }
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
   int j;
   while (str3[index] != '\0') {
      index++;
      lengthOfString++;
   }
  
   for ( j = 0; str4[j] != '\0' && j < num2; j++)
   {
      str3[lengthOfString + j] = str4[j];
      
      
   }
   str3[lengthOfString + num2] = '\0';

   
}

int stringNCompare(char *str5, char *str6, int num3) {
   while (num3 && *str5 && (*str5 == *str6))
   {
      ++str5;
      ++str6;
      --num3;
   }
   if( num3==0)
   {
      return 0;
   }
   else
   {
      return (*(unsigned char *)str5 - *(unsigned char *)str6);
   }
}