#pragma once
#include "meta.hpp"
#include "format.hpp"

namespace Logging {
    // Logger
    class Logger {
    public:
        // constructor / destructor
        Logger(const string& name);
        Logger(const string& name, const string& logfile);
        ~Logger();
        // log
        template<typename... TArgs>
        void log(const MsgMeta& meta, string_view fmt, const TArgs&... args) {
            if (int(m_Level) <= int(meta.level)) {
                stream(meta, (Format(fmt) << ... << args).close());
            }
        }
        // level
        Level getLevel() const;
        void setLevel(Level level);
    private:
        // stream
        void stream(const MsgMeta& meta, const string& msg);
        // member
        string m_Name;
        Opt<string> m_LogFile;
        Level m_Level;
        // static
        static inline std::mutex s_StreamMutex;
        static inline Map<string, fstream> s_Filestreams;
        static inline Map<string, int> s_FileRefCount;
    };
    // Macros !Make sure to define LOGGER before usage
    #define LOG_TRACE(...) LOGGER.log(::Logging::MsgMeta(::Logging::Level::Trace, LOCATION), __VA_ARGS__)
    #define LOG_DEBUG(...) LOGGER.log(::Logging::MsgMeta(::Logging::Level::Debug, LOCATION), __VA_ARGS__)
    #define LOG_INFO(...) LOGGER.log(::Logging::MsgMeta(::Logging::Level::Info, LOCATION), __VA_ARGS__)
    #define LOG_WARN(...) LOGGER.log(::Logging::MsgMeta(::Logging::Level::Warn, LOCATION), __VA_ARGS__)
    #define LOG_ERROR(...) LOGGER.log(::Logging::MsgMeta(::Logging::Level::Error, LOCATION), __VA_ARGS__)
    #define LOG_FATAL(...) LOGGER.log(::Logging::MsgMeta(::Logging::Level::Fatal, LOCATION), __VA_ARGS__)
}