// standard input output
#include <stdio.h>
//include the bool datatype so you can type bool instead of _Bool
#include <stdbool.h>
//library of string functions
#include <string.h>
int main(int argc, char * argv[]) {    //argc is arg counts

   int numberOfArguments = argc;
   char * argument1 = argv[0];
   char * argument2 = argv[1];

   printf("number of arguments: %d\n", numberOfArguments);
   printf("Argument 1 is the programme name: %s\n", argument1);
   printf("Argument 1 is the command line argument: %s\n", argument2);

   char str[100]; // this is a 99 character long character string, remember the null terminator
   char sampleChar = 'r'; // written in single quotes and displayes one and only one character
   char x = '\n'; // this is an escape character, stores an action into a special character 
   char exampleString[] = {"Hello mate"}; // best practive is to not specify the size. If I say !!!![100] then put one word we will still alocate memory for 100
   //there are lots of string functions in the string.h library with overflow problems use strncat rather than strcat

   //search for a character in a string
   char searchChar = 'm';
   char *searchResult = NULL;
   searchResult = strchr(exampleString, searchChar); // can do strstr to search a word
   printf("The \"m\" in the string was in position \"%s\"\n", searchResult);

   // can split a string into seperate words using strtok, it is called tokenising
   char sentance[] = "Hello my name is Louis";
   const char delin[] = " ";
   char *token;
   //get the first token
   token = strtok(sentance,delin);
   //get the rest of the tokens        !!!!!!! I don't understand this but I don't get pointers yet
   while (token != NULL){
      printf("%s\n", token);
      token = strtok(NULL, delin);
   }
}