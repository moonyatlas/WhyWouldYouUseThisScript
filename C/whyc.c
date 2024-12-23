/*
    WhyWouldYouUseThisScript Compiler, Version 0.0.1
    Made by therealrory
    
    This is bad
    There are things to fix, but i'll fix it later. I've worked on this for 8 hours already

    MIT License is to be applied.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    FILE *fptr;

    // Open the file in read mode
    fptr = fopen("../example.why", "r");

    if (fptr == NULL) { // Check if the file can be opened
        printf("Error opening file.\n");
        return 1;  // Exit the program with an error
    }

    char myString[100]; // Store the content of the file
    int buffer[9]; // The buffer thats used 
    int bufferSize = sizeof(buffer) / sizeof(buffer[0]);
    int tempone;
    int temptwo;
    // These two are used for arithmetic operations


    for (int i = 0; i < bufferSize; i++ ) {
        buffer[i] = 0; // Make sure the buffer is all zeros
    }

    while (fgets(myString, sizeof(myString), fptr)) { // Read line by line
        // Check if the line contains a semicolon (Aka a comment)
        char *semicolon_pos = strchr(myString, ';');
        
        if (semicolon_pos != NULL) {
            // If there's a semicolon, terminate the string at the semicolon
            *semicolon_pos = '\0';  // Replace semicolon with null terminator
        }

        // Remove any spaces or newline characters
        size_t len = strlen(myString);
        if (len > 0 && myString[len - 1] == '\n') {
            myString[len - 1] = '\0';  // Remove newline
        }
        while (len > 0 && myString[len - 1] == ' ') {
            myString[len - 1] = '\0';  // Remove spaces
            len--;
        }

        if (strlen(myString) > 0) { // Checks if its even longer than 0
            int digitcheck = isdigit(myString[0]); // This checks if its a @ or !


            if (digitcheck>0) {
                tempone = myString[0] - '0'; // Since we know this is not a symbol, we store the value. Also convert to integer

                if (myString[1] == '@') { // Store in buffer
                    buffer[myString[2] - '0'] = tempone;
                }

                // these above assume that the fourth character is @, it doesnt really matter ig

                else if (myString[1] == '+') { // Addition
                    temptwo = myString[2] - '0';
                    buffer[myString[4] - '0'] = buffer[tempone] + buffer[temptwo];
                }
                else if (myString[1] == '-') { // Subtraction
                    temptwo = myString[2] - '0';
                    buffer[myString[4] - '0'] = buffer[tempone] - buffer[temptwo];
                }
                else if (myString[1] == '*') { // Multiplication
                    temptwo = myString[2] - '0';
                    buffer[myString[4] - '0'] = buffer[tempone] * buffer[temptwo];
                }
                else if (myString[1] == '/') { // Division
                    temptwo = myString[2] - '0';
                    int index = myString[4] - '0';

                    if (buffer[temptwo] == 0) { // Division by zero check in the buffer
                        printf("Syntax error: Cannot divide by zero at buffer index %d\n", temptwo);
                    } else {
                        buffer[index] = buffer[tempone] / buffer[temptwo];
                }

                // Please forgive me yandere dev ass code
            }

            } else { // Checks the symbols if it wasnt a digit
                switch (myString[0]) {
                    case '!': // Printing buffer


                        printf("%d\n", buffer[myString[1] - '0']);
                        break;
                    
                    case '$': // "Freeing" Buffer Space
                        buffer[myString[1] - '0'] = 0;
                        break;
                    
                    default: // Cuh....
                        printf("Syntax error, ! nor $");
                        exit(1);
                }
            }
        }    


    }

    fclose(fptr);
    return 0;
}