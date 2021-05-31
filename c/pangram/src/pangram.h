#ifndef PANGRAM_H
#define PANGRAM_H

#include <stdbool.h>            //To use true or false
#include <ctype.h>              //To use isupper islower
#include <string.h>             //To use strlen

#define UPPER 65                //Char 'A' int number on the ascii table
#define LOWER 97                //Char 'a' int number on the ascii table
#define ALPHABET 26             //Number of characters in the alphabet

bool is_pangram(const char*);   //Define function template

#endif
