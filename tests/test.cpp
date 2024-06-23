// #include "logging.hpp"
#include "assert.hpp"
#include "default.hpp"
#include <thread> // std::thread

using namespace Beaver;
static Logger mylogger("My Logger", "logfile.log");
void logLargeInfo() {
    for (int i = 0; i < 100; ++i) {
        LOG_INFO("This is a very long info log in [Logger]! Thread-safety is garantueed across all logger classes. [{}]", i);
        mylogger.log(MsgMeta(Level::Info, LOCATION), "This is a very long info log in [My Logger]! Thread-safety is garantueed across all logger classes.");
    }
}
int main() {
    // default logger
    int count = 0;
    LOG_TRACE("message number {}, this is a trace!", ++count);
    LOG_DEBUG("message number {}, this is a debug!", ++count);
    LOG_INFO("message number {}, this is an info!", ++count);
    LOG_WARN("message number {}, this is a warning!", ++count);
    LOG_ERROR("message number {}, this is an error!", ++count);
    LOG_FATAL("message number {}, this is a fatal!", ++count);
    // override default logger
    setDefaultLogger(std::make_unique<Logger>("New Logger", "logfile.log"));
    LOG_INFO("message number {}, this is an info!", ++count);
    // owned logger
    #define LOGGER mylogger
    LOG_INFO("message number {}, this is an info!", ++count);
    // thread-safety
    // std::thread thread1(logLargeInfo);
    // std::thread thread2(logLargeInfo);
    // thread1.join();
    // thread2.join();
    ASSERT_MSG(true, "index out of bounds - required to be < {}", 3);
    ASSERT(0 == 0);
    return EXIT_SUCCESS;
}