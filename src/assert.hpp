#pragma once
#include "logger.hpp"

namespace Beaver {
    #define ASSERT(condition) if (condition) { LOG_FATAL(string("ASSERTION FAILED \"{}\""), (#condition)); exit(0); }
    #define ASSERT_MSG(condition, format, ...) if (condition) { LOG_FATAL(string("ASSERTION FAILED \"") + format + "\"", __VA_ARGS__); exit(0); }
}