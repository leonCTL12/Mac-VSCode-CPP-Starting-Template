#include <iostream>
#include <string>
#include "logger/ilogger.h"
#include "logger/console_logger.h"
#include "app.h"
#include <boost/di.hpp>

namespace di = boost::di;

int main()
{
    auto injector = di::make_injector(
        di::bind<ILogger>().to<ConsoleLogger>().in(di::singleton)); // singleton
    // di::bind<ILogger>().to<ConsoleLogger>()); // by default it is transient
    // di::bind<ILogger>().to<ConsoleLogger>().in(di::unique)); // to state it explicitly as transient
    auto app = injector.create<App>();
    app.run();
    return 0;
}