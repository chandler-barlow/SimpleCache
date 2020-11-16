#include <iostream>
#include "./Logger.cpp"


int main()
{
    Logger logger;
    logger.addEvent(3, 3, true);
    std::string log = logger.toString();
    std::cout << log;
    return 0;
}