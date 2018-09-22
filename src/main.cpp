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
    srand (time(NULL));
    Menu menu;
    std::string s;
    bool done = false;
	print("Welcome to StringManipulation. Type help to see list of commands",true);
    while(!done)
    {
        menu.show();
        std::cin >> s;
        std::cin.clear();
        std::size_t bracket = s.find("(");
        if(bracket != std::string::npos)
        {
            std::string cstr = s.substr(0,bracket);

            if(cstr == "showfile")
                command(s,FILE_GET);
            else if(cstr == "add_char")
                command(s,ADD_CHAR,3);
            else if(cstr == "savefile")
                command(s,FILE_SAVE,2);
            else if(cstr == "multiplychar")
                command(s,MULTIPLY_CHAR,2);
            else if(cstr == "reverse")
                command(s,REVERSE);
            else if(cstr == "remove")
                command(s,REMOVE,2);
            else if(cstr == "replace")
                command(s,REPLACE,3);
            else if(cstr == "to_upper")
                command(s,UPPER);
            else if(cstr == "to_lower")
                command(s,LOWER);
            else if(cstr == "to_bin")
                command(s,BINARY);
            else if(cstr == "to_hex")
                command(s,HEX);
            else if(cstr == "is_digit")
                command(s,IS_DIGIT);
            else if(cstr == "bin_to_dec")
                command(s,BIN_TO_DEC);
            else if(cstr == "bin_to_hex")
                command(s,BIN_TO_HEX);
            else if(cstr == "add")
                operationCommand(s,ADD);
            else if(cstr == "sub")
                operationCommand(s,SUBTRACT);
            else if(cstr == "multi")
                operationCommand(s,MULTIPLY);
            else if(cstr == "div")
                operationCommand(s,DIVIDE);
            else if(cstr == "is_prime")
                command(s,IS_PRIME);
            else if(cstr == "list_prime")
                command(s,LIST_PRIME,2);
            else if(cstr == "len")
                command(s,LEN);
            else if(cstr == "hex_to_dec")
                command(s,HEX_TO_DEC);
            else if(cstr == "hex_to_bin")
                command(s,HEX_TO_BIN);
            else if(cstr == "range")
                command(s,RANGE,3);
            else if(cstr == "count")
                command(s,COUNT,2);
            else if(cstr == "root")
                command(s,ROOT,2);
            else if(cstr == "random")
                command(s,RANDOM,2);
            else if(cstr == "to_opposite")
                command(s,TO_OPPOSITE);
            else
                print("That command doesn't exist. Try again!");
        }
        else
        {
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
            else
                print("That command doesn't exist. Try again!");
        }

        print("",true);
    }
}
