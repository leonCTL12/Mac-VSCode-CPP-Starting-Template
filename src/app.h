#pragma once
#include "logger/console_logger.h"
#include "calculator/calculator.h"

class App
{
public:
    explicit App(const ILogger &logger, const Calculator &calculator) : logger_(logger), calculator_(calculator) {}
    void run() const;
    const ILogger &logger_;
    const Calculator &calculator_;
};