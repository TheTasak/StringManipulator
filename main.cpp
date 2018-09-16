#include "Command.hpp"

class Menu
{
    std::vector<std::string> vec;
    void init()
    {
        vec.push_back(std::string(" " + String::multiply("_", std::to_string(X_SIZE)) + " "));
        for(int i = 0; i < Y_SIZE; i++)
            vec.push_back(std::string("|" + String::multiply(" ", std::to_string(X_SIZE)) + "|"));
        vec.push_back(std::string("|" + String::multiply("_", std::to_string(X_SIZE)) + "|"));
    }
public:
    Menu()
    {
        init();
    }
    void show()
    {
        Out::print("",true);
        Out::print(" >");
    }
	void clear()
	{
		Out::print(String::multiply("\n", std::to_string(SCREEN_SIZE)));
	}
};

int main()
{
    using namespace Out;
    using namespace Command;
    Menu menu;
    std::string s;
    bool done = false;
	print("Welcome to StringManipulation. Type help to see list of commands.",true);
    while(!done)
    {
        menu.show();
        std::cin >> s;
        std::cin.clear();
        if(s == "quit")
            done = true;
        else if(s == "help")
            commandShow();
        else if(s == "clear")
            menu.clear();
        else if(s == "clearacc")
            String::accumulator = 0;
        else if(s == "showlast")
            Out::print(String::lastResult);
        else if(s == "showacc")
            Out::print(String::accumulator);
        else if(!s.find("multiplychar"))
            command(s,MULTIPLY_CHAR,2);
        else if(!s.find("reverse"))
            command(s,REVERSE);
        else if(!s.find("remove"))
            command(s,REMOVE,2);
        else if(!s.find("replace"))
            command(s,REPLACE,3);
        else if(!s.find("to_upper"))
            command(s,UPPER);
        else if(!s.find("to_lower"))
            command(s,LOWER);
        else if(!s.find("to_bin"))
            command(s,BINARY);
        else if(!s.find("to_hex"))
            command(s,HEX);
        else if(!s.find("is_digit"))
            command(s,IS_DIGIT);
        else if(!s.find("bin_to_dec"))
            command(s,BIN_TO_DEC);
        else if(!s.find("bin_to_hex"))
            command(s,BIN_TO_HEX);
        else if(!s.find("add"))
            operationCommand(s,ADD);
        else if(!s.find("subtract"))
            operationCommand(s,SUBTRACT);
        else if(!s.find("multiply"))
            operationCommand(s,MULTIPLY);
        else if(!s.find("divide"))
            operationCommand(s,DIVIDE);
        else if(!s.find("is_prime"))
            command(s,IS_PRIME);
        else if(!s.find("list_prime"))
            command(s,LIST_PRIME,2);
        else if(!s.find("file"))
            Out::print(File::setGetFileText("file.txt", "Hello world"));
        else
            print("That command doesn't exist. Try again!");
        print("",true);
    }
}
