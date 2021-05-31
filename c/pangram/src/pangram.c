#include "pangram.h"

bool is_pangram(const char *sentence){

    char letter[ALPHABET] = {0};                //Initialize and set letter counter to zero

    if(sentence == (void*)0)                    //Test for null input
        return false;

    if(strlen(sentence) < 1)                    //Test for empty string
        return false;

    //Iterate through input to test char for valid letters

    for(int i = 0; sentence[i] != '\0'; i++){
        if(isupper(sentence[i]))                // Test for upper case
            letter[sentence[i] - UPPER] += 1;   // Increase letters count respectively by one
        if(islower(sentence[i]))                // Test for lower case
            letter[sentence[i] - LOWER] += 1;   // Increase letters count respectively by one
    }

    //Check count of letters

    for(int i = 0; i < ALPHABET; i++){
        if(letter[i] == 0)                      // Test to see if letter was included in input
            return false;
    }

    return true;
            
}
