#pragma once
#include "Utilities.hpp"
#include "String.hpp"
#include "File.hpp"
namespace Command
{
    void commandShow()
    {
        Out::print("GENERAL",true);
        Out::print("help - show help",true);
        Out::print("clear - clears screen",true);
        Out::print("clearacc - clears accumulator",true);
        Out::print("showlast - gets last result",true);
        Out::print("showacc - gets accumulator",true);

        Out::print("",true);
        Out::print("CHAR MANIPULATION",true);
        Out::print("multiplychar(string, int) - multiplies given string",true);
        Out::print("reverse(string) - reverses string",true);
        Out::print("remove(string, string) - removes second string from the first string",true);
        Out::print("replace(string, string, string) - replaces second string with third string in the first string",true);
        Out::print("to_upper(string) - changes characters to upper",true);
        Out::print("to_lower(string) - changes characters to lower",true);

        Out::print("",true);
        Out::print("NUMBER SYSTEMS",true);
        Out::print("to_bin(string) - changes characters to binary",true);
        Out::print("to_hex(string) - changes characters to hexadecimal",true);
        Out::print("bin_to_dec(string) - changes binary number to decimal",true);
        Out::print("bin_to_hex(string) - changes binary number to hexadecimal",true);

        Out::print("",true);
        Out::print("CALCULATOR",true);
        Out::print("add(int) - adds a number to accumulator",true);
        Out::print("add(int,int) - adds numbers to itselves",true);
        Out::print("subtract(int) - subtracts the number from accumulator",true);
        Out::print("subtract(int,int) - subtracts numbers from itselves",true);
        Out::print("multiply(int) - multiplies the number by accumulator",true);
        Out::print("multiply(int,int) - multiplies numbers",true);
        Out::print("divide(int) - divides accumulator by the number",true);
        Out::print("divide(int,int) - divides one number by another",true);
        Out::print("is_digit(string) - checks if all characters are numerical",true);
        Out::print("is_prime(int) - checks if number is prime",true);
        Out::print("list_prime(int,int) - list all prime numbers in range");
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
                default:
                    break;
                }
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
                default:
                    break;
                }
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
