#pragma once
#include "logger/console_logger.h"

class App
{
public:
    explicit App(const ILogger &logger) : logger_(logger) {}
    void run() const;
    const ILogger &logger_;
};