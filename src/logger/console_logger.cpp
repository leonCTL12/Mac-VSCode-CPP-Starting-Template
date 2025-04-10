#include "console_logger.h"
#include <iostream>

void ConsoleLogger::log(const std::string &msg) const
{
    std::cout << "ConsoleLogger: ";
    std::cout << msg << std::endl;
}