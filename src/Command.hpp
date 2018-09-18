#pragma once
#include "Utilities.hpp"
#include "String.hpp"
#include "File.hpp"
namespace Command
{
    int checkFlag(std::string input)
    {
        std::size_t par = input.find(")");
        if(par != std::string::npos)
        {
            std::string s = input.substr(par+1);
            String::remove(s,"");
            if(s == "-fin")
                return FLAG_FILEIN;
            else if(s == "-fout")
                return FLAG_FILEOUT;
            else if(s == "-finout")
                return FLAG_FILEINOUT;
            else
                return FLAG_BLANK;
        }
        else
            return FLAG_BLANK;
    }
    void commandShow()
    {
        std::string file = File::getFileText("src\\commands.txt");
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
        std::string o_1,o_2;
        o_1 = (one == "!" && String::lastResult != "") ? String::lastResult : one;
        o_2 = (two == "!" && String::lastResult != "") ? String::lastResult : two;
        String::lastResult = pointer(o_1,o_2);
    }
    template <typename T>
    void resultUpdate(std::string (*pointer)(T,T,T), std::string one, std::string two,std::string three)
    {
        std::string o_1,o_2,o_3;
        o_1 = (one == "!" && String::lastResult != "") ? String::lastResult : one;
        o_2 = (two == "!" && String::lastResult != "") ? String::lastResult : two;
        o_3 = (three == "!" && String::lastResult != "") ? String::lastResult : three;
        String::lastResult = pointer(o_1,o_2,o_3);
    }
    void command(std::string s,int type,int arguments = 1)
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
                switch(type)
                {
                case UPPER:
                    pointer = &String::to_upper;
                    break;
                case LOWER:
                    pointer = &String::to_lower;
                    break;
                case BINARY:
                    pointer = &String::to_binary;
                    break;
                case HEX:
                    pointer = &String::to_hex;
                    break;
                case BIN_TO_DEC:
                    pointer = &String::bin_to_dec;
                    break;
                case BIN_TO_HEX:
                    pointer = &String::bin_to_hex;
                    break;
                case IS_DIGIT:
                    pointer = &String::is_digit;
                    break;
                 case IS_PRIME:
                    pointer = &String::is_prime;
                    break;
                case REVERSE:
                    pointer = &String::reverse;
                    break;
                case FILE_GET:
                    pointer = &File::getFileText;
                    break;
                case LEN:
                    pointer = &String::length;
                    break;
                case HEX_TO_DEC:
                    pointer = &String::hex_to_dec;
                    break;
                case HEX_TO_BIN:
                    pointer = &String::hex_to_bin;
                    break;
                default:
                    break;
                }
                if(checkFlag(s) == FLAG_FILEIN || checkFlag(s) == FLAG_FILEINOUT)
                    first = File::getFileText(first);
                resultUpdate(pointer,first);
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
                switch(type)
                {
                case MULTIPLY_CHAR:
                    pointer = &String::multiply;
                    break;
                case REMOVE:
                    pointer = &String::remove;
                    break;
                case LIST_PRIME:
                    pointer = &String::listPrime;
                    break;
                case FILE_SAVE:
                    pointer = &File::setFileText;
                    break;
                default:
                    break;
                }
                if(checkFlag(s) == FLAG_FILEIN || checkFlag(s) == FLAG_FILEINOUT)
                    first = File::getFileText(first);
                resultUpdate(pointer,first,second);
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
                    switch(type)
                    {
                    case REPLACE:
                        pointer = &String::replace;
                        break;
                    default:
                        break;
                    }
                    if(checkFlag(s) == FLAG_FILEIN || checkFlag(s) == FLAG_FILEINOUT)
                        first = File::getFileText(first);
                    resultUpdate(pointer,first,second,third);
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
    void operationCommand(std::string s, int type)
    {
        std::size_t beginstr = s.find("(");
        std::size_t comma = s.find(",");
        std::size_t endstr = s.find(")");
        std::string str, removal;
        if(comma != std::string::npos && beginstr != std::string::npos && endstr != std::string::npos)
        {
            std::string a = s.substr(beginstr+1, comma - beginstr - 1);
            std::string b = s.substr(comma+1, endstr - comma - 1);

            std::string first = (a == "!" && String::lastResult != "") ? String::lastResult : a;
            std::string second = (b == "!" && String::lastResult != "") ? String::lastResult : b;
            String::lastResult = String::basicOperation(first,second,type);
            Out::print(String::lastResult);
        }
        else if(beginstr != std::string::npos && endstr != std::string::npos)
        {
            std::string a = s.substr(beginstr+1, endstr - beginstr - 1);

            std::string first = (a == "!" && String::lastResult != "") ? String::lastResult : a;
            String::basicOperation(first,type);
            Out::print(String::accumulator);
        }
        else
            Out::print(ERROR_NOTSPECIFIED);
    }
