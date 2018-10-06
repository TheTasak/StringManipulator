#pragma once

#include <iostream>
#include "windows.h"
#include <string>
#include <cmath>
#include <vector>
#include <bitset>
#include <iomanip>
#include <sstream>
#include <list>
#include <algorithm>
#include <iostream>
#include "windows.h"
#include <ctime>
#include <cstdlib>

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

#define LOWER "to_lower" // 1 argument
#define UPPER "to_upper"
#define BINARY "to_binary"
#define HEX "to_hex"
#define IS_DIGIT "is_digit"
#define BIN_TO_DEC "bin_to_dec"
#define BIN_TO_HEX "bin_to_hex"
#define IS_PRIME "is_prime"
#define REVERSE "reverse"
#define FILE_GET "showfile"
#define LEN "len"
#define HEX_TO_DEC "hex_to_dec"
#define HEX_TO_BIN "hex_to_bin"
#define TO_OPPOSITE "to_opposite"

#define REMOVE "remove" // 2 argument
#define MULTIPLY_CHAR "multichar"
#define LIST_PRIME "list_prime"
#define FILE_SAVE "savefile"
#define COUNT "count"
#define ROOT "root"
#define RANDOM "random"
#define BASIC_OPERATION "operation"

#define REPLACE "replace" // 3 argument
#define RANGE "range"
#define ADD_CHAR "add_char"
#define BASIC_ACC_OPERATION "accoperation"

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
