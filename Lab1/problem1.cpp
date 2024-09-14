//Write a program that finds the length of a text using pointers.
//Text is input as a string
//The maximum length of the text is 500 characters

#include <iostream>
#define MAX_SIZE 500//defines a constant, max size set to 500
using namespace std;

int main(){

    char text[MAX_SIZE]; //text is an array of characters that can hold up to MAX_SIZE characters. 
    char *ptr = text;//ptr is a pointer to the first element of text.
    int length = 0; //integer that will hold the length of the string.

    cout << "Please enter text, with a maximum of 500 characters: ";
    cin >> text;

    //Pointer points to first value of array
    *ptr = text[0];
    
    //incrementing the str pointer until it points to the null character '\0', which marks the end of the stirng
    //During each iteration of the loop, the count variable is incremented.
    while((*ptr++) != '\0'){ 
        length++; 
    }
    

    cout << "Number of characters in text: " << length;
}