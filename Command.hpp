#pragma once
#include "Utilities.hpp"
#include "String.hpp"

namespace Command
{
    void commandShow()
    {
        Out::print("GENERAL",true);
        Out::print("help - show help",true);
        Out::print("clear - clears screen",true);
        Out::print("clearacc - clears accumulator",true);

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
        Out::print("is_prime(int) - checks if number is prime");
    }
    void reverseCommand(std::string s)
    {
        std::size_t beginstr = s.find("(");
        std::size_t endstr = s.find(")");
        if(beginstr != std::string::npos && endstr != std::string::npos)
        {
            std::string str = s.substr(beginstr+1, endstr - beginstr - 1);
            if(str == "!" && String::lastResult != "")
                String::lastResult = String::reverse(String::lastResult);
            else
                String::lastResult = String::reverse(str);

            Out::print(String::lastResult);
        }
        else
            Out::print("Values not specified");
    }
    void multiplyCommand(std::string s)
    {
        std::size_t beginstr = s.find("(");
        std::size_t comma = s.find(",");
        std::size_t endstr = s.find(")");
        std::string str = "";
        int multiply = 0;
        if(comma != std::string::npos)
        {
            if(beginstr != std::string::npos && endstr != std::string::npos)
            {
                str = s.substr(beginstr+1, comma - beginstr - 1);
                std::string buf = s.substr(comma+1, endstr - comma - 1);
                multiply = std::stoi(buf);
                if(str == "!" && String::lastResult != "")
                    String::lastResult = String::multiply(String::lastResult, multiply);
                else
                    String::lastResult = String::multiply(str, multiply);

                Out::print(String::lastResult);
            }
        }
        else if(beginstr != std::string::npos && endstr != std::string::npos)
        {
            str = s.substr(beginstr+1, endstr - beginstr - 1);
            str.erase(str.end() - 1);
            if(str == "!" && String::lastResult != "")
                String::lastResult = String::multiply(String::lastResult);
            else
                String::lastResult = String::multiply(str);

            Out::print(String::lastResult);
        }
        else
            Out::print("Values not specified");
    }
    void removeCommand(std::string s)
    {
        std::size_t beginstr = s.find("(");
        std::size_t comma = s.find(",");
        std::size_t endstr = s.find(")");
        std::string str, removal;
        if(comma != std::string::npos && beginstr != std::string::npos && endstr != std::string::npos)
        {
            str = s.substr(beginstr+1, comma - beginstr - 1);
            removal = s.substr(comma+1, endstr - comma - 1);
            if(str == "!" && String::lastResult != "")
                String::lastResult = String::remove(String::lastResult,removal);
            else
                String::lastResult = String::remove(str, removal);

            Out::print(String::lastResult);
        }
        else
            Out::print("Values not specified");
    }
    void replaceCommand(std::string s)
    {
        std::size_t beginstr = s.find("(");
        std::size_t comma = s.find(",");
        std::size_t endstr = s.find(")");
        std::string str, removal, replacer;
        if(comma != std::string::npos)
        {
            std::size_t comma_sec = s.find(",", comma+1);
            if(comma_sec != std::string::npos && beginstr != std::string::npos && endstr != std::string::npos)
            {
                str = s.substr(beginstr+1, comma - beginstr - 1);
                removal = s.substr(comma+1, comma_sec - comma - 1);
                replacer = s.substr(comma_sec+1, endstr - comma_sec - 1);
                if(str == "!" && String::lastResult != "")
                    String::lastResult = String::replace(String::lastResult, removal, replacer);
                else
                    String::lastResult = String::replace(str, removal, replacer);

                Out::print(String::lastResult);
            }
            else
                Out::print("Values not specified");
        }
        else
            Out::print("Values not specified");
    }
    void basicCommand(std::string s,int toWhat)
    {
        std::size_t beginstr = s.find("(");
        std::size_t endstr = s.find(")");
        if(beginstr != std::string::npos && endstr != std::string::npos)
        {
            std::string str = s.substr(beginstr+1, endstr - beginstr - 1);
            switch(toWhat)
            {
            case UPPER:
                if(str == "!" && String::lastResult != "")
                    String::lastResult = String::to_upper(String::lastResult);
                else
                    String::lastResult = String::to_upper(str);
                break;
            case LOWER:
                if(str == "!" && String::lastResult != "")
                    String::lastResult = String::to_lower(String::lastResult);
                else
                    String::lastResult = String::to_lower(str);
                break;
            case BINARY:
                if(str == "!" && String::lastResult != "")
                    String::lastResult = String::to_binary(String::lastResult);
                else
                    String::lastResult = String::to_binary(str);
                break;
            case HEX:
                if(str == "!" && String::lastResult != "")
                    String::lastResult = String::to_hex(String::lastResult);
                else
                    String::lastResult = String::to_hex(str);
                break;
            case BIN_TO_DEC:
                if(str == "!" && String::lastResult != "")
                    String::lastResult = String::bin_to_dec(String::lastResult);
                else
                    String::lastResult = String::bin_to_dec(str);
                break;
            case BIN_TO_HEX:
                if(str == "!" && String::lastResult != "")
                    String::lastResult = String::bin_to_hex(String::lastResult);
                else
                    String::lastResult = String::bin_to_hex(str);
                break;
            case IS_DIGIT:
                bool isDigit;
                if(str == "!" && String::lastResult != "")
                    isDigit = String::is_digit(String::lastResult);
                else
                    isDigit = String::is_digit(str);
                isDigit ? Out::print("1") : Out::print("0");
                break;
             case IS_PRIME:
                if(str == "!" && String::lastResult != "")
                    String::lastResult = String::is_prime(String::lastResult);
                else
                    String::lastResult = String::is_prime(str);
                break;
            case LIST_PRIME:
                if(str == "!" && String::lastResult != "")
                    String::lastResult = String::listPrime(String::lastResult);
                else
                    String::lastResult = String::listPrime(str);
                break;
            default:
                break;
            }
            if(toWhat != IS_DIGIT)
                Out::print(String::lastResult);
        }
        else
            Out::print("Values not specified");
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

            if(a == "!" && b != "!" && String::lastResult != "")
                String::lastResult = String::basicOperation(String::lastResult, b, type);
            else if(a != "!" && b == "!" && String::lastResult != "")
                String::lastResult = String::basicOperation(a, String::lastResult,type);
            else if(a == "!" && b == "!" && String::lastResult != "")
                String::lastResult = String::basicOperation(String::lastResult, String::lastResult,type);
            else
                String::lastResult = String::basicOperation(a,b,type);
            Out::print(String::lastResult);
        }
        else if(beginstr != std::string::npos && endstr != std::string::npos)
        {
            std::string a = s.substr(beginstr+1, endstr - beginstr - 1);
            if(a == "!" && String::lastResult != "")
                String::basicOperation(String::lastResult,type);
            else
                String::basicOperation(a,type);
            Out::print(String::accumulator);
        }
        else
            Out::print("Values not specified");
    }
}
