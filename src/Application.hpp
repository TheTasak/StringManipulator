#pragma once
#include "Command.hpp"
#include "MathEngine.hpp"

class Application
{
    std::string globalInput = "";
    MathEngine me;
    bool done = false;
    void init()
    {
        Out::print(WELCOME_TEXT,true);
    }
    void show()
    {
        Out::print("",true);
        Out::print(" >");
    }
    void exit()
    {
        done = true;
    }
    inline bool checkInput()
    {
        return (bool)std::getline(std::cin,globalInput);
    }
    void clear()
    {
        Out::print(String::multiply("\n", std::to_string(SCREEN_SIZE)));
    }
public:
    Application()
    {
        init();
    }
    void loop()
    {
        while(!done)
        {
            show();
            if(checkInput())
            {
                checkCommand(globalInput);
                Out::print("",true);
            }
            else
            {
                globalInput = "";
                Out::print(ERROR_WRONGINPUT,true);
            }
        }
    }
    void checkCommand(std::string s)
    {
        std::size_t bracket = s.find("(");
        std::string str = (bracket != std::string::npos) ? s.substr(0,bracket) : s;
        std::string temp (1,str[0]);

        if(str == QUIT)             exit();
        else if(str == CLEAR)       clear();
        else if(isdigit(str[0]) || temp == CONTAINER || temp == LAST_RESULT)    Out::print(me.calculate(str));
        else                        Command::checkCommand(s);
    }
};
