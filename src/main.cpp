#include "Command.hpp"

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
        checkCommand(s);
        if(s == "quit")
            done = true;
        else if(s == "clear")
            menu.clear();
        print("",true);
    }
}
