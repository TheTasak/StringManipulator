#pragma once

#include "Utilities.hpp"

namespace String
{
    std::string lastResult = "";
    std::string container = "";
    long long accumulator = 0;

    static const char alphanum[] =
        "0123456789"
        "!@#$%^&*"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    static const char alpha[] = "abcdefghijklmnopqrstuvwxyz";

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
    std::string is_number(const std::string str)
    {
        if(str.length() > 1)
        {
            if(is_digit(str) == "True" && str[0] != '0')
                return "True";
        }
        else if(is_digit(str) == "True")
            return "True";
        return "False";
    }
    std::string error_size(std::string s, unsigned int i, std::string error)
    {
        if(s.length() >= i)
        {
            Out::print(error);
            return "";
        }
        return "a";
    }
    std::string error_isnumber(std::string s, std::string error)
    {
        if(String::is_number(s) == "False")
        {
            Out::print(error);
            return "";
        }
        return "a";
    }
    std::string setContainer(std::string s)
    {
        String::container = s;
        return "";
    }
    std::string multiply(const std::string str, const std::string i)
    {
        if(error_isnumber(i,ERROR_ARGUMENT2_TYPE) == "")
            return "";
        if(error_size(i,9,ERROR_ARGUMENT2_SIZE) == "")
            return "";
        unsigned int n = std::stoi(i) - 1;
        std::string str_copy = str;
        while(n-- > 0)
            str_copy += str;
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
    std::string is_prime(const std::string str)
    {
        if(error_isnumber(str,ERROR_ARGUMENT_TYPE) == "")
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
        if(a[0] == '-' && a.length() > 1)
        {
            isMinus = true;
            atemp.erase(atemp.begin());
        }
        else if(a[0] == '-' && a.length() <= 1)
            return ERROR_ARGUMENT_TYPE;
        if(error_isnumber(atemp,ERROR_ARGUMENT_TYPE) == "")
            return "";
        if(error_size(atemp,9,ERROR_ARGUMENT_SIZE) == "")
            return "";

        long long temp = std::stoll(atemp);
        if(isMinus) temp = -temp;
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
        if(a[0] == '-' && a.length() > 1)
        {
            isMinusA = true;
            atemp.erase(atemp.begin());
        }
        else if(a[0] == '-' && a.length() <= 1)
            return ERROR_ARGUMENT1_TYPE;
        if(b[0] == '-' && b.length() > 1)
        {
            isMinusB = true;
            btemp.erase(btemp.begin());
        }
        else if(b[0] == '-' && b.length() <= 1)
            return ERROR_ARGUMENT2_TYPE;
        if(error_isnumber(atemp,ERROR_ARGUMENT1_TYPE) == "")
            return "";
        if(error_isnumber(btemp,ERROR_ARGUMENT2_TYPE) == "")
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
        if(error_isnumber(str,ERROR_ARGUMENT2_TYPE) == "")
            return "";
        if(error_size(str,6,ERROR_ARGUMENT2_SIZE) == "")
            return "";
        if(error_isnumber(start,ERROR_ARGUMENT1_TYPE) == "")
            return "";
        if(error_size(start,6,ERROR_ARGUMENT1_SIZE) == "")
            return "";
        std::list<int> lis;
        int value = std::stoi(start);
        int value2 = std::stoi(str)+1;
        value = value < 2 ? 2 : value;
        if(value > value2 || value2 < 3)
            return "";
        Out::print("Started pushing values...",true);
        for(int i = 2; i < value2; i++)
            lis.push_back(i);
        Out::print("Ended pushing values",true);
        Out::print("Started removing complex numbers...",true);
        auto lastDivisor = std::find(lis.begin(), lis.end(), (int)std::sqrt(value2));
        for(auto i = lis.begin(); *i < *lastDivisor; ++i)
        {
            int multiply = *i;
            bool done = false;
            while(!done)
            {
                multiply += *i;
                if(multiply > value2)
                    done = true;
                else
                    lis.remove(multiply);
            }
        }
        auto removeNumbers = [&](int number) -> bool { return number < value; };
        auto it = std::remove_if(lis.begin(), lis.end(), removeNumbers);
        lis.erase(it,lis.end());

        Out::print("Ended removing complex numbers",true);
        return list_to_string(lis);
    }
    std::string range(const std::string start, const std::string stop, const std::string i)
    {
        if(error_isnumber(start,ERROR_ARGUMENT1_TYPE) == "")
            return "";
        if(error_size(start,6,ERROR_ARGUMENT1_SIZE) == "")
            return "";
        if(error_isnumber(stop,ERROR_ARGUMENT2_TYPE) == "")
            return "";
        if(error_size(stop,6,ERROR_ARGUMENT2_SIZE) == "")
            return "";
        if(error_isnumber(i,ERROR_ARGUMENT3_TYPE) == "")
            return "";
        if(error_size(i,6,ERROR_ARGUMENT3_SIZE) == "")
            return "";

        int a = std::stoi(start), b = std::stoi(stop);
        unsigned int in = std::stoi(i);
        if(in <= 0) return "Argument 3 must be greater than 0";
        std::string str = "";
        for(int i = a; i <= b; i += in)
            str += std::string(std::to_string(i) + " ");
        return str;
    }
    std::string count(const std::string s, const std::string fin)
    {
        bool done = false;
        unsigned int i = 0;
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
        if(error_isnumber(interval,ERROR_ARGUMENT3_TYPE) == "")
            return "";
        if(error_size(interval,6,ERROR_ARGUMENT3_SIZE) == "")
            return "";
        unsigned int inter = std::stoi(interval);
        std::string result = s;
        for(unsigned int i = 0; i < result.length(); i += inter)
        {
            result.insert(i, add);
            i += add.length();
        }
        return result;
    }
    std::string root(const std::string num, const std::string n)
    {
        if(error_isnumber(num,ERROR_ARGUMENT1_TYPE) == "")
            return "";
        if(error_size(num,6,ERROR_ARGUMENT1_SIZE) == "")
            return "";
        if(error_isnumber(n,ERROR_ARGUMENT2_TYPE) == "")
            return "";
        if(error_size(n,3,ERROR_ARGUMENT2_SIZE) == "")
            return "";
        int number = std::stoi(num),nt = std::stoi(n);
        if(nt < 1) return "1";
        else if(nt == 1) return std::to_string(number);

        float nthroot = std::pow(number,nt);
        int in = (int)std::floor(nthroot);
        if(in == -2147483648)
        {
            Out::print(ERROR_ARGUMENT_SIZE);
            return "";
        }
        return std::to_string(in);
    }
    std::string random(const std::string start, const std::string en)
    {
        if(error_isnumber(start,ERROR_ARGUMENT1_TYPE) == "")
            return "";
        if(error_size(start,6,ERROR_ARGUMENT1_SIZE) == "")
            return "";
        if(error_isnumber(en,ERROR_ARGUMENT2_TYPE) == "")
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
            if((unsigned int)c < 91) c = tolower(c);
            else c = toupper(c);
        }
        return newstr;
    }
    std::string factorial(const std::string s)
    {
        if(error_isnumber(s,ERROR_ARGUMENT_TYPE) == "")
            return "";
        if(error_size(s,3,ERROR_ARGUMENT_SIZE) == "")
            return "";
        unsigned int n = std::stoi(s);
        long long result = 1;
        if(n > 20) return "";
        while(n > 0)
            result *= n--;
        return std::to_string(result);
    }
    std::string toBase(const std::string num, const std::string beginBase,const std::string endBase) //todo base over 10
    {
        char charToDigit[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        if(error_size(num,6,ERROR_ARGUMENT1_SIZE) == "")
            return "";
        if(error_isnumber(beginBase,ERROR_ARGUMENT2_TYPE) == "")
            return "";
        if(error_size(beginBase,3,ERROR_ARGUMENT2_SIZE) == "")
            return "";
        if(error_isnumber(endBase,ERROR_ARGUMENT3_TYPE) == "")
            return "";
        if(error_size(endBase,3,ERROR_ARGUMENT3_SIZE) == "")
            return "";

        unsigned int bBase = std::stoi(beginBase), eBase = std::stoi(endBase);
        if(bBase < MIN_BASE || eBase < MIN_BASE || bBase > MAX_BASE || eBase > MAX_BASE) return ERROR_WRONGINPUT;
        for(char c : num)
        {
            bool isBase = false;
            for(unsigned int i = 0; i < bBase; i++)
            {
                if(charToDigit[i] == tolower(c))
                    isBase = true;
            }
            if(!isBase) return ERROR_WRONGINPUT; // check if numbers are legitimate in current base
        }
        int numInBase10 = 0;
        for(unsigned int i = 0; i < num.length(); i++)
        {
            char c = num[num.length()-i-1];
            char *p = std::find(std::begin(charToDigit),std::end(charToDigit),c);
            if(p == std::end(charToDigit))
                return ERROR_WRONGINPUT;
            numInBase10 +=  std::distance(charToDigit,p) * std::pow(bBase,i);
        }
        std::string result = "";
        while(numInBase10 > 0)
        {
            int modulo = numInBase10 % eBase;
            numInBase10 = std::floor(numInBase10 / eBase);
            result += std::to_string(modulo);
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
    std::string passwordGen(const std::string s)
    {
        if(error_isnumber(s,ERROR_ARGUMENT_TYPE) == "")
            return "";
        if(error_size(s,6,ERROR_ARGUMENT_SIZE) == "")
            return "";
        unsigned int num = std::stoi(s);
        std::string result = "";
        while(num-- > 0)
            result += alphanum[rand() % static_cast<int>(sizeof(alphanum) / sizeof(alphanum[0]) - 1)];
        return result;
    }
    std::string textGen(const std::string s)
    {
        if(error_isnumber(s,ERROR_ARGUMENT_TYPE) == "")
            return "";
        if(error_size(s,6,ERROR_ARGUMENT_SIZE) == "")
            return "";
        unsigned int num = std::stoi(s);
        std::string result = "";
        for(unsigned int i = 0; i < num; i++)
        {
            unsigned int randSentence = MIN_SENTENCE + (rand() % static_cast<int>(MAX_SENTENCE - MIN_SENTENCE));
            result += toupper(alpha[rand() % static_cast<int>(sizeof(alpha) / sizeof(alpha[0]) - 1)]);
            for(unsigned int i = 0; i < randSentence; i++)
            {
                unsigned int randWord = MIN_WORD + (rand() % static_cast<int>(MAX_WORD - MIN_WORD));
                while(randWord-- > 0)
                    result += alpha[rand() % static_cast<int>(sizeof(alpha) / sizeof(alpha[0]) - 1)];
                if(i+1 == randSentence)
                    result += ".";
                result += " ";
            }
        }
        return result;
    }
    std::string wordCount(const std::string s)
    {
        unsigned int c = 0;
        if(s != "") c = 1;
        for(unsigned int i = 0; i < s.length(); i++)
        {
            if(s[i] == ' ' && s[i+1] != ' ' && i+1 < s.length())
                c++;
        }
        return std::to_string(c);
    }
    std::string split(const std::string s, const std::string separator)
    {
        bool done = false;
        std::size_t found = -separator.length();
        std::string result = s;
        while(!done)
        {
            found = result.find(separator,found+separator.length());
            if(found != std::string::npos)
                result.insert(++found,"\n");
            else
                done = true;
        }
        return result;
    }
    std::string rotate(const std::string s, const std::string dir)
    {
        if(dir.length() != 1 && (dir[0] != 'l' && dir[0] != 'r'))
            return ERROR_ARGUMENT2_TYPE;
        if(s.length() < 2)
            return ERROR_ARGUMENT1_SIZE;
        std::string result = "";
        if(dir == "l")
            result += std::string(s.substr(1) + s[0]);
        else
            result += std::string(s[0] + s.substr(1));
        return result;
    }
    std::string to_ascii(const std::string s)
    {
        std::string result = "";
        for(char c : s)
            result += (std::string)std::to_string((int)c) + " ";
        return result;
    }
    std::string to_text(const std::string s)
    {
        bool done = false;
        unsigned int found = 0;
        unsigned int previous = 0;

        std::string result, strcopy = s;
        if(strcopy[0] != ' ') strcopy = " " + s;
        if(strcopy[strcopy.size()-1] != ' ') strcopy += " ";

        while(!done)
        {
            previous = found;
            for(unsigned int i = found+1; i < strcopy.size(); i++)
            {
                found = strcopy[i] == ' ' ? i : found;
                if(found == i) break;
            }
            if(found == previous)
                done = true;
            else
            {
                std::string con = strcopy.substr(previous,found-previous);
                for(auto c : con)
                    if(!isdigit(c) && c != ' ') return ERROR_ARGUMENT_TYPE;
                int val = std::stoi(con);
                result += (char)val;
            }
        }
        return result;
    }
    std::string removetext(std::string s)
    {
        s.erase(std::remove_if(s.begin(),s.end(),[](unsigned char x){return std::isalpha(x);}),s.end());
        return s;
    }
    std::string removenumbers(std::string s)
    {
        s.erase(std::remove_if(s.begin(),s.end(),[](unsigned char x){return std::isdigit(x);}),s.end());
        return s;
    }
    std::string removerange(std::string s,const std::string begin, const std::string end)
    {
        if(begin.size() > 9 || end.size() > 9)
            return ERROR_ARGUMENT_SIZE;
        if(error_isnumber(begin,ERROR_ARGUMENT2_TYPE) == "")
            return "";
        if(error_isnumber(end,ERROR_ARGUMENT3_TYPE) == "")
            return "";
        unsigned int b = std::stoi(begin), e = std::stoi(end);
        if(e < b || e > s.size() || b < 0 || b > s.size())
            return "Wrong range input";
        s.erase(s.begin()+b,s.end()-(s.size()-e));
        return s;
    }
    std::string removenth(std::string s, const std::string nth)
    {
        if(error_size(nth,9,ERROR_ARGUMENT2_SIZE) == "" )
            return "";
        if(error_isnumber(nth,ERROR_ARGUMENT2_TYPE) == "")
            return "";
        unsigned int a = std::stoi(nth);
        for(unsigned int i = a; i < s.size(); i += a-1)
            s.erase(s.begin()+i,s.begin()+i+1);
        return s;
    }
    /*std::string ls()
    {
        std::string dirlist = "";

        std::string path = std::filesystem::current_path().string();
        for(const auto entry : std::filesystem::directory_iterator(path))
            dirlist += (std::string)entry.path().string() + "\n";
        return dirlist;
    }*/
}
