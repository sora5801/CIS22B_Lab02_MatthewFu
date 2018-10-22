/*CIS 22B
Lab 02: Test four custom cstring functions
Name: Matthew Fu
Date: 10/23/18

Program description: This program asks the user which custom cstring functions he wants to test.
There are four of them: a custom strlen function, a custom strncpy function, a custom strncat
function, and a custon strncmp function. After choosing one, the user is asked for a string.
If the user chooses the custom strlen option or the custom strncpy function, the user
is asked only one string. If the user chooses the custom strncat function or the custom
strncmp function, the user is asked for two strings. The user is asked for a number
for the custom strncpy, strncat, and strncmp function. This number represents, respectively,
the maximum number of characters to be copied, maximum number of characters to be appended,
and maximum number of character so compare.
*/

#include <iostream>
#include <cstring>

using namespace std;

//Function prototypes declared up here.
int stringLength(char *given_string);
void stringNCopy(char *destinationPointer, char *sourcePointer, int num);
void stringNAdd(char *destinationPointer, char *sourcePointer, int num2);
int stringNCompare(char *firstString, char *secondString, int num3);


/*Pseudocode:
Declare the maximum size of the char input
Declare a char to ask the user for repeated testing
start a do-while loop
   Prompt user for input
   Declare the first char array
   Declare the second char array
   Declare a user option input
   Declare a number option
   If the user presses L, test the custom stringLength function
   else if the user presses C, test the custom stringNCopy function
   else if the user presses A, test the custom stringNAdd function
   else if the user presses M, test the custom stringNCompare function
      if the function returns a positive, the first string is greater than the second
      if the function returns a negative, the second string is greater than the first
      if the function returns a 0, the two strings are equal to each other
   else give an invalid output 
   Prompt the user if he would like to test again.
      if Y, then the test repeats
      else the program closes.
return 0*/
int main() {
   //Maximum size of the char input
   const int SIZE = 100;
   
   cout << "We have 4 string functions to test.\n\n\n";
   char again;
   do {
      // Prompt the user for which function they want to test out.
      cout << "Input L if you want to test out the stringLength function, C if you want to test out stringNCopy, " <<
         " \nA if you want to test out the stringNAdd function, and M if you want to test out the stringNCompare function" << endl;
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
      //The user is prompted only one  string as there shall be no overlapping.
      else if (userInput == 'C') {
         cout << "Enter a sentence of no more than "
            << (SIZE - 1) << " characters:\n";
         cin.ignore();
         cin.getline(line, SIZE);
         cout << "Enter a number less than " << stringLength(line) << endl;
         cin >> number;
         stringNCopy(line2, line, number);
         cout << line2  << endl;
      }
      //Test the stringNAdd function
      //The first string is limited to 99 characters. The second string 
      //cannot be greater than that because the destination string has to be large
      //enough to contain the concatenated resulting string, including the null.
      else if (userInput == 'A') {
         cout << "Enter a sentence of no more than "
            << (SIZE - 1) << " characters:\n";
         cin.ignore();
         cin.getline(line, SIZE);
         cout << "Enter another sentence of no more than "
            << (SIZE - 1 - stringLength(line)) << " characters:\n";
       
         cin.getline(line2, SIZE);
         cout << "Enter a number less than " << SIZE - stringLength(line) << endl;
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
void stringNAdd(char *destinationPointer, char *sourcePointer, int num2) {
  //point to the end of the first char
   char* pointerToDestination = destinationPointer + stringLength(destinationPointer);

   while (*sourcePointer != '\0' && num2--)
      *pointerToDestination++ = *sourcePointer++;

   *pointerToDestination = '\0';
     
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
int stringNCompare(char *firstString, char *secondString, int num3) {
   while (num3 && *firstString && (*firstString == *secondString))
   {
      ++firstString; //traverse the address of the first string
      ++secondString; //traverse the address of the second string
      --num3; //decrease the maximum number
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
      return (*(unsigned char *)firstString - *(unsigned char *)secondString);
   }
}