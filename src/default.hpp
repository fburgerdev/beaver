#pragma once
#include "logger.hpp"

namespace Beaver {
    // setDefaultLogger
    void setDefaultLogger(unique_ptr<Logger>&& logger);
    // getDefaultLogger
    Logger& getDefaultLogger();
    // Macro
    #define LOGGER ::Beaver::getDefaultLogger()
}