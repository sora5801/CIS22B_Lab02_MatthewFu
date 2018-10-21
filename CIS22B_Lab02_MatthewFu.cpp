/*CIS 22B
Lab 02: Test four custom cstring functions
Name: Matthew Fu
Date: 10/23/18

Program description: This program asks the user which custom cstring functions he wants to test.
There are four of them: a custom strlen function, a custom strncpy function, a custom strncat
function, and a custon strncmp function. 
*/

#include <iostream>
#include <cstring>

using namespace std;

//Function prototypes declared up here.
int stringLength(char* given_string);
void stringNCopy(char *str1, char* str2, int num);
char* stringNAdd(char* str3, char *str4, int num2);
int stringNCompare(char *str5, char *str6, int num3);



int main() {
   //Maximum size of the char input
   const int SIZE = 100;
   
   cout << "We have 4 string functions to test.\n\n\n";
   char again;
   do {
      // Prompt the user for which function they want to test out.
      cout << "Input L if you want to test out the stringLength function, C if you want to test out stringNCopy, " <<
         " \n A if you want to test out the stringNAdd function, and M if you want to test out the stringNCompare function" << endl;
      char line[SIZE]; //First string
      char line2[SIZE]; //Second string
      char userInput; //Input option
      int number; 
      cin >> userInput;
      //Test the stringLength function
      if (userInput == 'L') {
         cout << "Enter a sentence of no more than "
            << (SIZE - 1) << " characters:\n";
         cin.ignore();
         cin.getline (line, SIZE); 
         cout << stringLength(line) << endl;
      }
      //Test the stringNCopy function
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
      //Test the stringNAdd function
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
         cout << line << endl;         
      }
      //Test the stringNCompare function
      else if (userInput == 'M') {
         cout << "Enter a sentence of no more than "
            << (SIZE - 1) << " characters:\n";
         cin.ignore();
         cin.getline(line, SIZE);
         cout << "Enter another sentence of no more than "
            << (SIZE - 1) << " characters:\n";
         
         cin.getline(line2, SIZE);
         cout << "Enter a number less than " << SIZE << endl;
         cin >> number;
         cout << stringNCompare(line, line2, number) <<endl;
         if (stringNCompare(line, line2, number) > 0)
            cout << "The first string is greater than the second string." << endl;
         if (stringNCompare(line, line2, number) < 0)
            cout << "The second string is greater than the first string." << endl;
         if (stringNCompare(line, line2, number) == 0)
            cout << "The two strings are equal to each other." << endl;
      }
      else {
         cout << "Invalid Input \n";
      }

      cout << "Would you like to run the program again? (Y/N): " << endl;
      cin >> again;
   } while (again == 'y' || again == 'Y');
   return 0;
}

/*Pseudocode:
Set the counter variable (length) to 0
While the given char pointer has not pointed to null
   increment counter
   increment given address
return the length of the string
*/
int stringLength(char* given_string)
{

   int length = 0;
   while (*given_string != '\0') {
      length++;
      given_string++;
   }

   return length;
}

/*Pseudocode:
while the char source pointer has not pointed to null and the given number is still decreasing
   Set the destination pointer to be equal to the source pointer and increment both of them

set the destination pointer to be null
*/
void stringNCopy(char *destinationPointer, char *sourcePointer, int num) {
   while (*sourcePointer != '\0' && num--)
   {
      *destinationPointer++ = *sourcePointer++;    
   }
   *destinationPointer = '\0';
}

/*Pseudocode:
Set the pointer for destination to the end of the destination 
While the source pointer has not hit null and the incoming number is still decreasing
   Set the pointer for destination to be equal to the source pointer and increment both of them

set the destination pointer to be null
*/
char* stringNAdd(char *destinationPointer, char *sourcePointer, int num2) {
  
   char* pointerToDestination = destinationPointer + stringLength(destinationPointer);

   while (*sourcePointer != '\0' && num2--)
      *pointerToDestination++ = *sourcePointer++;

   *pointerToDestination = '\0';
   

   return destinationPointer;
}

/*Pseudocode:
While the given number is not zero and the first string has not reached the end
and the first string is equal to the second string
   Increase the address of the first string
   Increase the address of the string
   Decrease the given number
if the number is equal to 0(this means that the first string matches the second string up to the given number)
   return 0
else
   return the difference in the value of ASCII value of the two strings. */
int stringNCompare(char *str5, char *str6, int num3) {
   while (num3 && *str5 && (*str5 == *str6))
   {
      ++str5;
      ++str6;
      --num3;
   }
   if( num3==0)
   {
      //If the first string is equal to the second string, then 0 is returned.
      return 0;
   }
   else
   {
      //If the value returned is less than 0, then the first string is less than the second
      //else the opposite is true.
      return (*(unsigned char *)str5 - *(unsigned char *)str6);
   }
}