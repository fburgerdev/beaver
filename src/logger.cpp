#include "logger.hpp"
#include <mutex> // std::mutex, std::lock_guard
#include <filesystem> // std::filesystem::absolute

namespace Beaver {
    // Logger
    // Logger :: constructor / destructor
    Logger::Logger(const string& name)
        : m_Name(name), m_LogFile(), m_Level(Level::Trace) {}
    Logger::Logger(const string& name, const string& logfile)
        : m_Name(name), m_LogFile(std::filesystem::absolute(logfile).string()), m_Level(Level::Trace) {
        std::lock_guard lock(s_StreamMutex);
        if (s_Filestreams.contains(m_LogFile.value())) {
            s_FileRefCount[m_LogFile.value()]++;
        }
        else {
            int size = s_Filestreams.size();
            s_Filestreams.emplace(m_LogFile.value(), std::fstream(logfile));
            s_FileRefCount[m_LogFile.value()] = 1;
        }
    }
    Logger::~Logger() {
        if (m_LogFile) {
            std::lock_guard lock(s_StreamMutex);
            s_FileRefCount[m_LogFile.value()]--;
            if (s_FileRefCount[m_LogFile.value()] == 0) {
                s_Filestreams.erase(m_LogFile.value());
                s_FileRefCount.erase(m_LogFile.value());
            }
        }
    }
    // Logger :: stream
    void Logger::stream(const MsgMeta& meta, const string& msg) {
        // color
        string ansicolor;
        switch (meta.level) {
        case Level::Trace:
            ansicolor = "\033[37m"; // white
            break;
        case Level::Debug:
            ansicolor = "\033[34m"; // blue
            break;
        case Level::Info:
            ansicolor = "\033[32m"; // green
            break;
        case Level::Warn:
            ansicolor = "\033[33m"; // yellow
            break;
        case Level::Error:
            ansicolor = "\033[31m"; // red
            break;
        case Level::Fatal:
            ansicolor = "\033[31m\033[4m"; // red underline
            break;
        default:
            break;
        }
        // stream
        std::lock_guard lock(s_StreamMutex); // lock streams
        std::ostream& stream = (int(meta.level) <= int(Level::Info) ? cout : cerr); // select cout / cerr depending on level
        stream << ansicolor << '[' << m_Name << "] " << meta << "\n\033[0m\033[38;5;245m" << msg << "\033[0m\n\n"; // stream to console
        if (m_LogFile) {
            s_Filestreams[m_LogFile.value()] << '[' << m_Name << "] " << meta << '\n' << msg << '\n' << '\n'; // stream to logfile
        }
    }
    // Logger :: level
    Level Logger::getLevel() const {
        return m_Level;
    }
    void Logger::setLevel(Level level) {
        m_Level = level;
    }
}