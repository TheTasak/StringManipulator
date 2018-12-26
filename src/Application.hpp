#pragma once
#include "Command.hpp"

class Application
{
    std::string globalInput = "";
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
    bool checkInput()
    {
        if(!std::getline(std::cin,globalInput))
			return false;
        else
			return true;
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

        if(str == QUIT)             exit();
        else if(str == CLEAR)       clear();
        else                        Command::checkCommand(s);
    }
};
