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
#define ERROR_WRONGINPUT "Input is not correct. Try again"
#define ERROR_COMMAND_NOT_DEFINED "That command doesn't exist. Try again!"

#define FLAG_BLANK ""
#define FLAG_FILEIN "-fin"
#define FLAG_FILEOUT "-fout"
#define FLAG_FILEINOUT "-finout"

#define X_SIZE 112
#define Y_SIZE 13
#define SCREEN_SIZE 30

#define HELP "help" // 0 argument
#define CLEAR_ACC "clearacc"
#define CLEAR_LAST "clearlast"
#define CLEAR "clear"
#define QUIT "quit"
#define SHOW_ACC "showacc"
#define SHOW_LAST "showlast"

#define LOWER "to_lower" // 1 argument
#define UPPER "to_upper"
#define IS_DIGIT "is_digit"
#define IS_PRIME "is_prime"
#define REVERSE "reverse"
#define FILE_GET "showfile"
#define LEN "len"
#define TO_OPPOSITE "to_opposite"
#define FACTORIAL "fac"
#define PASSWORD_GEN "passgen"
#define TEXT_GEN "textgen"

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
#define TO_BASE "to_base"


#define COMMAND_FILEPATH "src\\commands.txt"
#define WELCOME_TEXT "Welcome to StringManipulation. Type help to see list of commands"
#define MIN_BASE 2
#define MAX_BASE 10

#define MAX_WORD 12
#define MIN_WORD 3
#define MAX_SENTENCE 12
#define MIN_SENTENCE 2
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
