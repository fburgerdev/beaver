#include "default.hpp"

using namespace Logging;
int main() {
    setDefaultLogger(unique_ptr<Logger>(new Logger("TEST")));
    LOG_TRACE("Hallo {}, ich heiße Florian und bin {} Jahre alt.", "Olga", 20, 10);
    LOG_DEBUG("Hallo {}, ich heiße Florian und bin {} Jahre alt.", "Olga", 20, 10);
    LOG_INFO("Hallo {}, ich heiße Florian und bin {} Jahre alt.", "Olga", 20, 10);
    LOG_WARN("Hallo {}, ich heiße Florian und bin {} Jahre alt.", "Olga", 20, 10);
    LOG_ERROR("Hallo {}, ich heiße Florian und bin {} Jahre alt.", "Olga", 20, 10);
    LOG_FATAL("Hallo {}, ich heiße Florian und bin {} Jahre alt.", "Olga", 20, 10);
    return EXIT_SUCCESS;
}