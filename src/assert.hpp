#pragma once
#include "logger.hpp"

namespace Beaver {
    #define ASSERT(condition, format, ...) if (condition) { LOG_FATAL(string("ASSERT FAILED: ") + format, __VA_ARGS__); exit(0); }
}