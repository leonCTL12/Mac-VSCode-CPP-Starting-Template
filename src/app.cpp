#include "app.h"
#include <iostream>

void App::run() const
{
    logger_.log("Application started");
    double result = calculator_.add(5, 3);

    std::cout << "Result of addition: " << result << std::endl;
}