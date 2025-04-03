#include <iostream>
#include <string>
#include "logger/ilogger.h"
#include "logger/console_logger.h"
#include "app.h"

int main()
{
    ConsoleLogger logger;
    App app(logger);
    app.run();
    return 0;
}