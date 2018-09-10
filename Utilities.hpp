#pragma once

#include <iostream>
#include "windows.h"

#define ERROR_ARGUMENT1_TYPE "Argument no.1 is not a number"
#define ERROR_ARGUMENT2_TYPE "Argument no.2 is not a number"
#define ERROR_ARGUMENT_TYPE "Input is not a number"
#define ERROR_ARGUMENT1_SIZE "Argument no.1 is too big"
#define ERROR_ARGUMENT2_SIZE "Argument no.2 is too big"
#define ERROR_ARGUMENT_SIZE "Input is too big"

#define X_SIZE 112
#define Y_SIZE 13
#define SCREEN_SIZE 30

#define LOWER 0
#define UPPER 1
#define BINARY 2
#define HEX 3
#define IS_DIGIT 4
#define BIN_TO_DEC 5
#define BIN_TO_HEX 6
#define IS_PRIME 7
#define LIST_PRIME 8

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
