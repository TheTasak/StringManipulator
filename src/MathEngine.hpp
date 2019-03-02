#pragma once
#include "Utilities.hpp"
#include <list>

class MathEngine //currently with +,-,*,/
{
    //v0.3.2 only operation on two numbers
    std::string input;
    std::list<std::string> inputarray;
    int lastresult;
    std::list<std::string> splitInput(std::string s)
    {
        std::list<std::string> lis;
        std::string num = "";
        for(unsigned int i = 0; i < s.size(); i++)
        {
            if(s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*')
            {
                if(num != "")
                {
                    lis.push_back(num);
                    num = "";
                }
                lis.push_back(std::to_string(s[i]));
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
    std::list<std::string> checkLoop(std::list<std::string> lis, std::string a, std::string b)
    {
        for(unsigned int i = 1; i < lis.size(); i++)
        {
            std::list<std::string>::iterator it = std::next(lis.begin(),i);
            if(*it == a || *it == b)
            {
                std::list<std::string> temp;
                for(unsigned int n = 0; n < 3; n++)
                {
                    temp.push_back(*std::prev(it));
                    lis.erase(std::prev(it));
                }
                int result = fastcalc(temp);
                lis.insert(std::prev(it),std::to_string(result));
                i = 1;
            }
        }
        return lis;
    }
    int fastcalc(std::list<std::string> lis)
    {
        std::list<std::string>::iterator it = std::next(lis.begin(),1);
        std::string c = *it;
        int a = std::stoi(*std::prev(it)),b = std::stoi(*std::next(it));
        if(c == "43")      return a + b;
        else if(c == "45") return a - b;
        else if(c == "42") return a * b;
        else if(c == "47") return a / b;

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
        if(lis.size() == 3)
            lis = {std::to_string(fastcalc(lis))};
        lastresult = std::stoi(lis.front());
        return std::stoi(lis.front());
    }
};
