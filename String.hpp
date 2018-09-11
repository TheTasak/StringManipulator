#pragma once

#include <string>
#include <cmath>
#include <vector>
#include <bitset>
#include <iomanip>
#include <sstream>
#include <list>
#include <iostream>
#include "windows.h"

#include "Utilities.hpp"

namespace String
{
    std::string lastResult;
    long long accumulator = 0;

    std::string reverse(const std::string str = "")
    {
        std::string new_str = "";
        for(int i = str.length() - 1; i >= 0; i--)
            new_str += str[i];
        return new_str;
    }
    std::string remove(const std::string str, const std::string rem)
    {
        if(rem.length() <= 0 || str.length() <= 0)
            return str;
        bool done = false;
        std::string newstr = str;
        while(!done)
        {
            std::size_t found = newstr.find(rem);
            if(found != std::string::npos)
                newstr.erase(found, rem.length());
            else
                done = true;
        }
        return newstr;
    }
    std::string replace(const std::string str, const std::string del, const std::string rep)
    {
        if(str.length() <= 0 || del.length() <= 0 || rep.length() <= 0)
            return str;
        bool done = false;
        std::string newstr = str;
        while(!done)
        {
            std::size_t found = newstr.find(del);
            if(found != std::string::npos)
                newstr.replace(found, del.length(), rep);
            else
                done = true;
        }
        return newstr;
    }
    std::string is_digit(const std::string str)
    {
        for(char c : str)
        {
            if(!isdigit(c))
                return "False";
        }
        return "True";
    }
    std::string error_size(std::string s, int i, std::string error)
    {
        if(s.length() >= i)
        {
            Out::print(error);
            return "";
        }
        return "a";
    }
    std::string error_isdigit(std::string s, std::string error)
    {
        if(String::is_digit(s) == "False")
        {
            Out::print(error);
            return "";
        }
        return "a";
    }
    std::string multiply(const std::string str, const std::string i)
    {
        if(error_isdigit(i,ERROR_ARGUMENT2_TYPE) == "")
            return "";
        if(error_size(i,9,ERROR_ARGUMENT2_SIZE) == "")
            return "";
        int n = std::stoi(i);
        n--;
        std::string str_copy = str;
        while(n > 0)
        {
            str_copy += str;
            n--;
        }
        return str_copy;
    }
    std::string to_upper(const std::string str)
    {
        std::string newstr = str;
        for(int i = 0; i < newstr.size(); i++)
            newstr[i] = toupper(newstr[i]);
        return newstr;
    }
    std::string to_lower(const std::string str)
    {
        std::string newstr = str;
        for(int i = 0; i < newstr.size(); i++)
            newstr[i] = tolower(newstr[i]);
        return newstr;
    }
    std::string to_binary(const std::string str)
    {
        std::string newstr = "";
        if(error_isdigit(str,ERROR_ARGUMENT_TYPE) == "")
            return "";
        if(error_size(str,9,ERROR_ARGUMENT_SIZE) != "")
        {
            if(std::stoi(str) <= 255)
                newstr = std::bitset<8>(std::stoi(str)).to_string();
            else if(std::stoi(str) <= 65535)
                newstr = std::bitset<16>(std::stoi(str)).to_string();
            else
                newstr = std::bitset<32>(std::stoi(str)).to_string();
            return newstr;
        }
        else
            return "";
    }
    std::string to_hex(const std::string str)
    {
        std::stringstream sstream;
        if(error_isdigit(str,ERROR_ARGUMENT_TYPE) == "")
            return "";
        if(error_size(str,9,ERROR_ARGUMENT_SIZE) != "")
        {
            int num = std::stoi(str);
            int result;
            sstream << num;
            sstream >> std::hex >> result;
            if(sstream.fail())
            {
                Out::print("Something went wrong...");
                return "";
            }
            return std::to_string(result);
        }
        else
            return "";
    }
    std::string bin_to_dec(const std::string str)
    {
        for(char c : str)
        {
            if(c != '1' && c != '0')
            {
                Out::print("Number is not binary");
                return "";
            }
        }
        if(error_size(str,31,ERROR_ARGUMENT_SIZE) != "")
        {
            std::string newstr = str;
            int result = 0, base = 1;
            for(int i = newstr.length()-1; i >= 0; i--)
            {
                if(newstr[i] == '1')
                    result += base;
                base = base * 2;
            }
            return std::to_string(result);
        }
        else
            return "";
    }
    std::string bin_to_hex(const std::string str)
    {
        std::string temp = bin_to_dec(str);
        if(temp == "") return "";
        temp = to_hex(temp);
        return temp;
    }
    std::string is_prime(const std::string str)
    {
        if(error_isdigit(str,ERROR_ARGUMENT_TYPE) == "")
            return "";
        if(error_size(str,9,ERROR_ARGUMENT_SIZE) == "")
            return "";
        int i,n = std::stoi(str);
        for(i = 2; i <= n / 2; ++i)
        {
            if(n % i == 0)
                return "False";
        }
        return "True";
    }
    void basicOperation(const std::string a, int operation)
    {
        bool isMinus = false;
        std::string atemp = a;
        if(a[0] == '-')
        {
            isMinus = true;
            atemp.erase(atemp.begin());
        }
        if(error_isdigit(atemp,ERROR_ARGUMENT_TYPE) == "")
            return;
        if(error_size(atemp,9,ERROR_ARGUMENT_SIZE) == "")
            return;

        long long temp = std::stoll(atemp);
        temp = isMinus ? -temp : temp;
		String::lastResult = std::to_string(temp);
        switch(operation)
        {
        case ADD:
            String::accumulator += temp;
            break;
        case SUBTRACT:
            String::accumulator -= temp;
            break;
        case MULTIPLY:
            String::accumulator *= temp;
            break;
        case DIVIDE:
            if(temp != 0)
                String::accumulator /= temp;
            break;
        }

    }
    std::string basicOperation(const std::string a, const std::string b, int operation)
    {
        std::string atemp = a;
        std::string btemp = b;
        bool isMinusA = false, isMinusB = false;
        if(a[0] == '-')
        {
            isMinusA = true;
            atemp.erase(atemp.begin());
        }
        if(b[0] == '-')
        {
            isMinusB = true;
            btemp.erase(btemp.begin());
        }
        if(error_isdigit(atemp,ERROR_ARGUMENT1_TYPE) == "")
            return "";
        if(error_isdigit(btemp,ERROR_ARGUMENT2_TYPE) == "")
            return "";
        if(error_size(atemp,9,ERROR_ARGUMENT1_SIZE) == "")
            return "";
        if(error_size(btemp,9,ERROR_ARGUMENT2_SIZE) == "")
            return "";

        long long temp, temp2;
        temp = std::stoll(atemp);
        temp2 = std::stoll(btemp);
        temp = isMinusA ? -temp : temp;
        temp2 = isMinusB ? -temp2 : temp2;
        long long result;
        switch(operation)
        {
        case ADD:
            result = temp + temp2;
            break;
        case SUBTRACT:
            result = temp - temp2;
            break;
        case MULTIPLY:
            result = temp * temp2;
            break;
        case DIVIDE:
            if(temp2 != 0)
                result = temp / temp2;
            else
                result = temp2;
            break;
        }
        return std::to_string(result);
    }
    std::string list_to_string(const std::list<int> vec)
    {
        std::list<int> newvec = vec;
        std::string str = "";
        for(int i = 0; i < vec.size(); i++)
        {
            str += std::to_string(vec.front());
            newvec.pop_back();
        }
        return str;
    }
    std::string listPrime(const std::string str)
    {
        if(error_isdigit(str,ERROR_ARGUMENT_TYPE) == "")
            return "";
        if(error_size(str,8,ERROR_ARGUMENT_SIZE) == "")
            return "";
        std::list<int> lis;
        int value = std::stoi(str);
        int greatestPosDivisor = std::sqrt(value);
        Out::print(greatestPosDivisor,true);
        Out::print("Started pushing values...",true);
        for(int i = 0; i < value; i++)
            lis.push_back(i);
        Out::print("Ended pushing values...",true);
        /*if(lis.size() < 3)
            return list_to_string(lis);
        for(int i = 2; i <= greatestDivisor; i++)
        {
            int multiply = lis[i];
            while(multiply <= value)
            {
                multiply += multiply;
                lis.erase(i);
            }
        }
        lis.erase(1);
        lis.erase(0);*/
        return list_to_string(lis);
    }
}
