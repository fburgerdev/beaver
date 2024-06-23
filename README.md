# Description
>C++ library for console and file logging

This project provides a *Logger* class that allows for formatted logging to the console (cout, cerr) and, optionally, to a logfile.

Logs are labelled with and filtered by one of the following logging levels:
- Trace (cout)
- Debug (cout)
- Info (cout)
- Warning (cerr)
- Error (cerr)
- Fatal (cerr)

*Thread-safety* is garantueed across all logger instances.

# Interface
```cpp
namespace Beaver {
    // Level
    enum class Level {
        Trace,
        Debug,
        Info,
        Warn,
        Error,
        Fatal
    };
    // Location
    struct Location {};
    #define LOCATION -> Location
       
    // Meta
    struct MsgMeta {
        // constructor
        MsgMeta(Level level, const Location& location);
    };    
    // Logger
    struct Logger {
        // constructor
        Logger(const string& name);
        Logger(const string& name, const string& logfile);
        // log
        template<typename... TArgs>
        void log(MsgMeta&& meta, std::string_view& format, const TArgs&... args);
        // level
        void setLevel(Level);
        Level getLevel() const;
    };    
    // default logger
    void setDefaultLogger(unique_ptr<Logger>&& logger);
    Logger& getDefaultLogger();
    
    // macros
    #define LOGGER ::Beaver::getDefaultLogger()
    #define LOG_TRACE(...)
    #define LOG_DEBUG(...)
    #define LOG_INFO(...)
    #define LOG_WARN(...)
    #define LOG_ERROR(...)
    #define LOG_FATAL(...)
}
```
# Examples
## Default Logger
```cpp
## foo.cpp
#include "logging.hpp"

void foo() {
    // optional: set default logger
    Beaver::setDefaultLogger(std::make_unique<Logger>("Default"));
    // streams to newly set default logger "Default"
    LOG_INFO("This is an info that your lucky number is {}", 7)
}
```
## Own Logger
```cpp
## debug.hpp
#pragma once
#include "logging.hpp"

// construct own logger and make it accessible by the logging macros
static inline Beaver::Logger debug("Debug", "./debug.log");
#define LOGGER debug
```
```cpp
## foo.cpp
#include "debug.hpp"

void foo() {
    // streams to own logger "Debug"
    LOG_INFO("This is an info that your lucky number is {}", 7)
}
```

# Use this Project
## Installation
At your desired location, type this command into the console.
``` console
git clone git@github.com:fburgerdev/logging.git
```

## Include in Project
In your C++ project:
- add the include directory "PATH_TO_THIS_REPO/include" 
- add the library directory "PATH_TO_THIS_REPO/lib/DESIRED_CONFIG/" 
- link the library "liblogging.a" (linux) or "logging.lib" (windows)

## Build Yourself (optional)
### with Linux
In the _build_ folder, execute the following command in the console
``` console
make config=CONFIG
```
If you have not installed _make_, execute this command in the console first
``` console
sudo apt-get install make -y
```

### with Windows
Open the file "build/logging.sln" with Visual Studio.
After you have selected your desired configuration, click on _Build > Build_ Solution.

__Note:__ Make sure you have the _Desktop developement with C++_ workload installed.