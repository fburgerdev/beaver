#pragma once
#include "logger.hpp"

namespace Beaver {
    #define ASSERT(condition) if (!(condition)) { LOG_FATAL(string("ASSERTION FAILED \"{}\""), (#condition)); exit(EXIT_FAILURE); }
    #define ASSERT_MSG(condition, format, ...) if (!(condition)) { LOG_FATAL(string("ASSERTION FAILED \"") + format + "\"", __VA_ARGS__); exit(EXIT_FAILURE); }
}