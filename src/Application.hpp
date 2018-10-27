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
        using namespace Command;
        std::size_t bracket = s.find("(");
        std::string str = (bracket != std::string::npos) ? s.substr(0,bracket) : s;

        if(str == FILE_GET)                 command(s,FILE_GET);
        else if(str == ADD_CHAR)            command(s,ADD_CHAR,3);
        else if(str == FILE_SAVE)           command(s,FILE_SAVE,2);
        else if(str == MULTIPLY_CHAR)       command(s,MULTIPLY_CHAR,2);
        else if(str == REVERSE)             command(s,REVERSE);
        else if(str == REMOVE)              command(s,REMOVE,2);
        else if(str == REPLACE)             command(s,REPLACE,3);
        else if(str == UPPER)               command(s,UPPER);
        else if(str == LOWER)               command(s,LOWER);
        else if(str == IS_DIGIT)            command(s,IS_DIGIT);
        else if(str == IS_PRIME)            command(s,IS_PRIME);
        else if(str == LIST_PRIME)          command(s,LIST_PRIME,2);
        else if(str == LEN)                 command(s,LEN);
        else if(str == RANGE)               command(s,RANGE,3);
        else if(str == COUNT)               command(s,COUNT,2);
        else if(str == ROOT)                command(s,ROOT,2);
        else if(str == RANDOM)              command(s,RANDOM,2);
        else if(str == TO_OPPOSITE)         command(s,TO_OPPOSITE);
        else if(str == BASIC_OPERATION)     command(s,BASIC_OPERATION,3);
        else if(str == BASIC_ACC_OPERATION) command(s,BASIC_ACC_OPERATION,2);
        else if(str == FACTORIAL)           command(s,FACTORIAL);
        else if(str == PASSWORD_GEN)        command(s,PASSWORD_GEN);
        else if(str == TEXT_GEN)            command(s,TEXT_GEN);
        else if(str == TO_BASE)             command(s,TO_BASE,3);
        else if(str == HELP)                commandShow();
        else if(str == CLEAR_ACC)           String::accumulator = 0;
        else if(str == SHOW_LAST)           Out::print(String::lastResult);
        else if(str == SHOW_ACC)            Out::print(String::accumulator);
        else if(str == CLEAR_LAST)          String::lastResult = "";
        else if(str == QUIT)                exit();
        else if(str == CLEAR)               clear();
        else if(str == SET_CONTAINER)       command(s,SET_CONTAINER);
        else if(str == CLEAR_CONTAINER)     String::container = "";
        else if(str == SHOW_CONTAINER)      Out::print(String::container);
        else                                Out::print(ERROR_COMMAND_NOT_DEFINED);
    }
};
