#include "application.hpp"

int main()
{
    Application *application = new Application;
    application->run();
    delete application;
    return 0;
}
