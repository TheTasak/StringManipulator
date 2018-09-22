#pragma once

#include <iostream>
#include "windows.h"

#define ERROR_ARGUMENT1_TYPE "Argument no.1 is not a number"
#define ERROR_ARGUMENT2_TYPE "Argument no.2 is not a number"
#define ERROR_ARGUMENT3_TYPE "Argument no.3 is not a number"
#define ERROR_ARGUMENT_TYPE "Input is not a number"
#define ERROR_ARGUMENT1_SIZE "Argument no.1 is too big"
#define ERROR_ARGUMENT2_SIZE "Argument no.2 is too big"
#define ERROR_ARGUMENT3_SIZE "Argument no.3 is too big"
#define ERROR_ARGUMENT_SIZE "Input is too big"
#define ERROR_NOTSPECIFIED "Arguments not specified"
#define ERROR_OPENFILE "File could not be opened"

#define FLAG_BLANK 0
#define FLAG_FILEIN 1
#define FLAG_FILEOUT 2
#define FLAG_FILEINOUT 3

#define X_SIZE 112
#define Y_SIZE 13
#define SCREEN_SIZE 30

#define LOWER 0 // 1 argument
#define UPPER 1
#define BINARY 2
#define HEX 3
#define IS_DIGIT 4
#define BIN_TO_DEC 5
#define BIN_TO_HEX 6
#define IS_PRIME 7
#define REVERSE 8
#define FILE_GET 9
#define LEN 10
#define HEX_TO_DEC 11
#define HEX_TO_BIN 12
#define TO_OPPOSITE 13

#define REMOVE 0 // 2 argument
#define MULTIPLY_CHAR 1
#define LIST_PRIME 2
#define FILE_SAVE 3
#define COUNT 4
#define ROOT 5
#define RANDOM 6

#define REPLACE 0 // 3 argument
#define RANGE 1
#define ADD_CHAR 2

#define ADD 0
#define SUBTRACT 1
#define MULTIPLY 2
#define DIVIDE 3

namespace Out
{
	template<typename T>
    void print(const T val, const bool newline = false)
    {
        std::cout << val;
        if(newline)
            std::cout << std::endl;
    }
}
