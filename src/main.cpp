#include "Command.hpp"

std::string globalInput = "";
bool checkInput()
{
    if(!std::getline(std::cin,globalInput)) return false;
    else return true;
}
int main()
{
    using namespace Out;
    using namespace Command;
    srand (time(NULL));
    Menu menu;
    bool done = false;
	print("Welcome to StringManipulation. Type help to see list of commands",true);
    while(!done)
    {
        menu.show();
        if(checkInput())
        {
            checkCommand(globalInput);
            if(globalInput == "quit")
                done = true;
            else if(globalInput == "clear")
                menu.clear();
            print("",true);
        }
        else
        {
            globalInput = "";
            print("Input is not correct. Try again",true);
        }
    }
}
