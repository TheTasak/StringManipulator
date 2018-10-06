#pragma once

#include "Utilities.hpp"

namespace String
{
    std::string lastResult;
    long long accumulator = 0;

    inline std::string length(const std::string str)
    {
        return std::to_string(str.length());
    }
    std::string reverse(const std::string str)
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
        std::size_t found = -rep.length();
        while(!done)
        {
            found = newstr.find(del,found+rep.length());
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
        for(char &c : newstr)
            c = toupper(c);
        return newstr;
    }
    std::string to_lower(const std::string str)
    {
        std::string newstr = str;
        for(char &c : newstr)
            c = tolower(c);
        return newstr;
    }
    std::string to_binary(const std::string str)
    {
        std::string newstr = "";
        if(error_isdigit(str,ERROR_ARGUMENT_TYPE) == "")
            return "";
        if(error_size(str,9,ERROR_ARGUMENT_SIZE) == "")
            return "";
        if(std::stoi(str) <= 255)
            newstr = std::bitset<8>(std::stoi(str)).to_string();
        else if(std::stoi(str) <= 65535)
            newstr = std::bitset<16>(std::stoi(str)).to_string();
        else
            newstr = std::bitset<32>(std::stoi(str)).to_string();
        return newstr;
    }
    std::string to_hex(const std::string str)
    {
        std::stringstream sstream;
        if(error_isdigit(str,ERROR_ARGUMENT_TYPE) == "")
            return "";
        if(error_size(str,9,ERROR_ARGUMENT_SIZE) == "")
            return "";
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
        return to_hex(temp);
    }
    std::string hex_to_dec(const std::string str)
    {
        if(error_isdigit(str,ERROR_ARGUMENT_TYPE) == "")
            return "";
        if(error_size(str,9,ERROR_ARGUMENT_SIZE) == "")
            return "";
        std::stringstream sstream;
        int i = std::stoi(str);
        sstream << i;
        sstream >> std::hex >> i;
        return std::to_string(i);
    }
    std::string hex_to_bin(const std::string str)
    {
        std::string temp = hex_to_dec(str);
        if(temp == "") return "";
        return to_binary(temp);
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
    std::string basicAccOperation(const std::string a, const std::string operation)
    {
        bool isMinus = false;
        std::string atemp = a;
        if(a[0] == '-')
        {
            isMinus = true;
            atemp.erase(atemp.begin());
        }
        if(error_isdigit(atemp,ERROR_ARGUMENT_TYPE) == "")
            return "";
        if(error_size(atemp,9,ERROR_ARGUMENT_SIZE) == "")
            return "";

        long long temp = std::stoll(atemp);
        temp = isMinus ? -temp : temp;
		String::lastResult = std::to_string(temp);
		if(operation == "+") String::accumulator += temp;
		else if(operation == "-") String::accumulator -= temp;
		else if(operation == "*") String::accumulator *= temp;
		else if(operation == "/") String::accumulator = (temp != 0) ? String::accumulator /= temp : String::accumulator;
		else Out::print("Incorrect operation",true);
		return std::to_string(String::accumulator);
    }
    std::string basicOperation(const std::string a, const std::string b, const std::string operation)
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
        if(operation == "+") result = temp + temp2;
		else if(operation == "-") result = temp - temp2;
		else if(operation == "*") result = temp * temp2;
		else if(operation == "/") result = (temp2 != 0) ? temp / temp2 : temp2;
		else Out::print("Incorrect operation",true);
        return std::to_string(result);
    }
    std::string list_to_string(const std::list<int> vec)
    {
        std::string str = "";
        for(auto i = vec.begin(); i != vec.end(); ++i)
            str += std::string(std::to_string(*i) + " ");
        return str;
    }

    std::string listPrime(const std::string start, const std::string str)
    {
        if(error_isdigit(str,ERROR_ARGUMENT2_TYPE) == "")
            return "";
        if(error_size(str,6,ERROR_ARGUMENT2_SIZE) == "")
            return "";
        if(error_isdigit(start,ERROR_ARGUMENT1_TYPE) == "")
            return "";
        if(error_size(start,6,ERROR_ARGUMENT1_SIZE) == "")
            return "";
        std::list<int> lis;
        int value = std::stoi(start);
        int value2 = std::stoi(str);
        value = value < 2 ? 2 : value;
        if(value > value2 || value2 < 3)
            return "";
        Out::print("Started pushing values...",true);
        for(int i = 2; i < value2; i++)
            lis.push_back(i);
        Out::print("Ended pushing values",true);
        Out::print("Started removing complex numbers...",true);
        auto lastDivisor = std::find(lis.begin(), lis.end(), std::sqrt(value2));
        for(auto i = lis.begin(); i != lastDivisor; ++i)
        {
            int multiply = *i,constant = *i;
            bool done = false;
            while(!done)
            {
                multiply += constant;
                if(multiply > value2)
                    done = true;
                else
                    lis.remove(multiply);
            }
        }
        auto removeNumbers = [&](int number) -> bool
        {
            return number < value;
        };
        auto it = std::remove_if(lis.begin(), lis.end(), removeNumbers);
        lis.erase(it,lis.end());
        Out::print("Ended removing complex numbers",true);
        return list_to_string(lis);
    }
    std::string range(const std::string start, const std::string stop, const std::string i)
    {
        if(error_isdigit(start,ERROR_ARGUMENT1_TYPE) == "")
            return "";
        if(error_size(start,6,ERROR_ARGUMENT1_SIZE) == "")
            return "";
        if(error_isdigit(stop,ERROR_ARGUMENT2_TYPE) == "")
            return "";
        if(error_size(stop,6,ERROR_ARGUMENT2_SIZE) == "")
            return "";
        if(error_isdigit(i,ERROR_ARGUMENT3_TYPE) == "")
            return "";
        if(error_size(i,6,ERROR_ARGUMENT3_SIZE) == "")
            return "";

        int a = std::stoi(start), b = std::stoi(stop), in = std::stoi(i);
        std::string str = "";
        for(int i = a; i <= b; i += in)
            str += std::string(std::to_string(i) + " ");
        return str;
    }
    std::string count(const std::string s, const std::string fin)
    {
        bool done = false;
        int i = 0;
        std::size_t found = -fin.length();
        while(!done)
        {
            found = s.find(fin,found+fin.length());
            if(found != std::string::npos)
                i++;
            else
                done = true;
        }
        return std::to_string(i);
    }
    std::string addChar(const std::string s, const std::string add, const std::string interval)
    {
        if(error_isdigit(interval,ERROR_ARGUMENT3_TYPE) == "")
            return "";
        if(error_size(interval,6,ERROR_ARGUMENT3_SIZE) == "")
            return "";
        int inter = std::stoi(interval);
        std::string result = s;
        for(int i = 0; i < result.length(); i += inter)
        {
            result.insert(i, add);
            i += add.length();
        }
        return result;
    }
    std::string root(const std::string num, const std::string n)
    {
        if(error_isdigit(num,ERROR_ARGUMENT1_TYPE) == "")
            return "";
        if(error_size(num,6,ERROR_ARGUMENT1_SIZE) == "")
            return "";
        if(error_isdigit(n,ERROR_ARGUMENT2_TYPE) == "")
            return "";
        if(error_size(n,2,ERROR_ARGUMENT2_SIZE) == "")
            return "";
        int number = std::stoi(num),nt = std::stoi(n);
        int nthroot = std::pow(number,nt);
        return std::to_string(nthroot);
    }
    std::string random(const std::string start, const std::string en)
    {
        if(error_isdigit(start,ERROR_ARGUMENT1_TYPE) == "")
            return "";
        if(error_size(start,6,ERROR_ARGUMENT1_SIZE) == "")
            return "";
        if(error_isdigit(en,ERROR_ARGUMENT2_TYPE) == "")
            return "";
        if(error_size(en,6,ERROR_ARGUMENT2_SIZE) == "")
            return "";
        int a = std::stoi(start), b = std::stoi(en);
        int output = a + (rand() % static_cast<int>(b - a + 1));
        return std::to_string(output);
    }
    std::string to_opposite(const std::string s)
    {
        std::string newstr = s;
        for(char &c : newstr)
        {
            if((int)c < 91) c = tolower(c);
            else c = toupper(c);
        }
        return newstr;
    }
}
