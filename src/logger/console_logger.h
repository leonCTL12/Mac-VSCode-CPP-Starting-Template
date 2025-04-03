#pragma once
#include <iostream>
#include <string>
#include "ilogger.h"

class ConsoleLogger : public ILogger
{
public:
    void log(const std::string &msg) const;
};