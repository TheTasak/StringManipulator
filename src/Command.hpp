#pragma once
#include "Utilities.hpp"
#include "String.hpp"
#include "File.hpp"
namespace Command
{
    std::string checkFlag(std::string input)
    {
        std::size_t par = input.find(")");
        if(par != std::string::npos)
        {
            std::string s = input.substr(par+1);
            std::string flag = s;
            std::size_t found;
            found = s.find(FLAG_FILEINOUT);
            if(found != std::string::npos)
                return FLAG_FILEINOUT;
            found = s.find(FLAG_FILEOUT);
            if(found != std::string::npos)
                return FLAG_FILEOUT;
            found = s.find(FLAG_FILEIN);
            if(found != std::string::npos)
                return FLAG_FILEIN;
            else
                return FLAG_BLANK;
        }
        else
            return FLAG_BLANK;
    }
    std::string getFileName(std::string input)
    {
        std::size_t found = input.find("?");
        if(found == std::string::npos)
            return "";
        std::string s = input.substr(found+1);
        found = s.find("?");
        if(found == std::string::npos)
            return "";
        s.erase(found);
        return s;
    }
    void commandShow()
    {
        std::string file = File::getFileText(COMMAND_FILEPATH);
        Out::print(file);
    }
    template <typename T>
    void resultUpdate(std::string (*pointer)(T), std::string one)
    {
        if(one == "!" && String::lastResult != "")
            String::lastResult = pointer(String::lastResult);
        else
            String::lastResult = pointer(one);
    }
    template <typename T>
    void resultUpdate(std::string (*pointer)(T,T), std::string one, std::string two)
    {
        std::string o_1 = (one == "!" && String::lastResult != "") ? String::lastResult : one;
        std::string o_2 = (two == "!" && String::lastResult != "") ? String::lastResult : two;
        String::lastResult = pointer(o_1,o_2);
    }
    template <typename T>
    void resultUpdate(std::string (*pointer)(T,T,T), std::string one, std::string two,std::string three)
    {
        std::string o_1 = (one == "!" && String::lastResult != "") ? String::lastResult : one;
        std::string o_2 = (two == "!" && String::lastResult != "") ? String::lastResult : two;
        std::string o_3 = (three == "!" && String::lastResult != "") ? String::lastResult : three;
        String::lastResult = pointer(o_1,o_2,o_3);
    }
    void command(std::string s,std::string type,int arguments = 1)
    {
        std::size_t beginstr = s.find("(");
        std::size_t endstr = s.find(")");
        std::string first;
        if(arguments == 1)
        {
            if(beginstr != std::string::npos && endstr != std::string::npos)
            {
                first = s.substr(beginstr+1, endstr - beginstr - 1);
                std::string (*pointer)(std::string);

                if(type == UPPER)               pointer = &String::to_upper;
                else if(type == LOWER)          pointer = &String::to_lower;
                else if(type == BINARY)         pointer = &String::to_binary;
                else if(type == HEX)            pointer = &String::to_hex;
                else if(type == BIN_TO_DEC)     pointer = &String::bin_to_dec;
                else if(type == BIN_TO_HEX)     pointer = &String::bin_to_hex;
                else if(type == IS_DIGIT)       pointer = &String::is_digit;
                else if(type == IS_PRIME)       pointer = &String::is_prime;
                else if(type == REVERSE)        pointer = &String::reverse;
                else if(type == REVERSE)        pointer = &String::reverse;
                else if(type == REVERSE)        pointer = &String::reverse;
                else if(type == FILE_GET)       pointer = &File::getFileText;
                else if(type == LEN)            pointer = &String::length;
                else if(type == HEX_TO_DEC)     pointer = &String::hex_to_dec;
                else if(type == HEX_TO_BIN)     pointer = &String::hex_to_bin;
                else if(type == TO_OPPOSITE)    pointer = &String::to_opposite;

                if(checkFlag(s) == FLAG_FILEIN || checkFlag(s) == FLAG_FILEINOUT)
                    first = File::getFileText(first);
                resultUpdate(pointer,first);
                if(checkFlag(s) == FLAG_FILEOUT || checkFlag(s) == FLAG_FILEINOUT)
                {
                    std::string filename = getFileName(s);
                    if(!filename.empty()) File::setFileText(filename,String::lastResult);
                }
                Out::print(String::lastResult);
            }
            else
                Out::print(ERROR_NOTSPECIFIED);
        }
        else if(arguments == 2)
        {
            std::size_t comma = s.find(",");
            if(comma != std::string::npos && beginstr != std::string::npos && endstr != std::string::npos)
            {
                first = s.substr(beginstr+1, comma - beginstr - 1);
                std::string second = s.substr(comma+1, endstr - comma - 1);
                std::string (*pointer)(std::string,std::string);

                if(type == MULTIPLY_CHAR)               pointer = &String::multiply;
                else if(type == REMOVE)                 pointer = &String::remove;
                else if(type == LIST_PRIME)             pointer = &String::listPrime;
                else if(type == FILE_SAVE)              pointer = &File::setFileText;
                else if(type == COUNT)                  pointer = &String::count;
                else if(type == ROOT)                   pointer = &String::root;
                else if(type == RANDOM)                 pointer = &String::random;
                else if(type == BASIC_ACC_OPERATION)    pointer = &String::basicAccOperation;

                if(checkFlag(s) == FLAG_FILEIN || checkFlag(s) == FLAG_FILEINOUT)
                    first = File::getFileText(first);
                resultUpdate(pointer,first,second);
                if(checkFlag(s) == FLAG_FILEOUT || checkFlag(s) == FLAG_FILEINOUT)
                {
                    std::string filename = getFileName(s);
                    if(!filename.empty()) File::setFileText(filename,String::lastResult);
                }
                Out::print(String::lastResult);
            }
            else
                Out::print(ERROR_NOTSPECIFIED);
        }
        else if(arguments == 3)
        {
            std::size_t comma = s.find(",");
            if(comma != std::string::npos)
            {
                std::size_t comma_sec = s.find(",", comma+1);
                std::string second,third;
                std::string (*pointer)(std::string,std::string,std::string);
                if(comma_sec != std::string::npos && beginstr != std::string::npos && endstr != std::string::npos)
                {
                    first = s.substr(beginstr+1, comma - beginstr - 1);
                    second = s.substr(comma+1, comma_sec - comma - 1);
                    third = s.substr(comma_sec+1, endstr - comma_sec - 1);

                    if(type == REPLACE)                 pointer = &String::replace;
                    else if(type == RANGE)              pointer = &String::range;
                    else if(type == ADD_CHAR)           pointer = &String::addChar;
                    else if(type == BASIC_OPERATION)    pointer = &String::basicOperation;

                    if(checkFlag(s) == FLAG_FILEIN || checkFlag(s) == FLAG_FILEINOUT)
                        first = File::getFileText(first);
                    resultUpdate(pointer,first,second,third);
                    if(checkFlag(s) == FLAG_FILEOUT || checkFlag(s) == FLAG_FILEINOUT)
                    {
                        std::string filename = getFileName(s);
                        if(!filename.empty()) File::setFileText(filename,String::lastResult);
                    }
                    Out::print(String::lastResult);
                }
                else
                    Out::print(ERROR_NOTSPECIFIED);
            }
        }
        else
            Out::print(ERROR_NOTSPECIFIED);
    }
}
