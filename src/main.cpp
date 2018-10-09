#include "Application.hpp"

int main()
{
    using namespace Command;
    srand (time(NULL));
    Application app;
	app.loop();
}
