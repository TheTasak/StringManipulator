#pragma once
#include "Utilities.hpp"
#include <list>

class MathEngine //currently with +,-,*,/
{
    std::string input;
    std::list<std::string> inputarray;
    int lastresult;
    std::list<std::string> splitInput(std::string s)
    {
        std::list<std::string> lis;
        std::string num = "";
        std::string symbol = "";
        for(unsigned int i = 0; i < s.size(); i++)
        {
            if(s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*')
            {
                if(num != "")
                {
                    lis.push_back(num);
                    num = "";
                }
                symbol = s[i];
                lis.push_back(symbol);
            }
            else if(isdigit(s[i]))
                num += s[i];
            else if(s[i] != ' ')
            {
                Out::print("Unknown input. Returning error...",true);
                break;
            }
        }
        lis.push_back(num);
        return lis;
    }
    void checkLoop(std::list<std::string> &lis, std::string a, std::string b)
    {
        for(unsigned int i = 1; i < lis.size(); i++)
        {
            std::list<std::string>::iterator it = std::next(lis.begin(),i);
            if(*it == a || *it == b) //check for symbols
            {
                std::list<std::string> temp;
                lis.splice(temp.begin(),temp,std::prev(it),std::next(it,2)); // splice singular operation
                int result = fastcalc(temp);
                lis.insert(std::next(lis.begin(),i-1),std::to_string(result)); //insert result to equation
                i = 1;
            }
        }
    }
    int fastcalc(std::list<std::string> lis)
    {
        std::list<std::string>::iterator it = std::next(lis.begin(),1);
        std::string c = *it;
        int a = std::stoi(*std::prev(it)),b = std::stoi(*std::next(it));
        if(c == "+")      return a + b;
        else if(c == "-") return a - b;
        else if(c == "*") return a * b;
        else if(c == "/") return a / b;

        return 0;
    }
    public:
    MathEngine()
    {
        input = "";
        inputarray.clear();
        lastresult = 0;
    }
    inline void showCalculate()
    {
        Out::print(lastresult,true);
    }
    int calculate(std::string s)
    {
        std::list<std::string> lis = splitInput(s);
        checkLoop(lis,"*","/");
        checkLoop(lis,"+","-");
        lastresult = std::stoi(lis.front());
        return std::stoi(lis.front());
    }
};
