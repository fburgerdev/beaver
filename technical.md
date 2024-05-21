## Interface
```cpp
namespace Logging {
	// Level
	enum class Level {
		Trace,
		Debug,
		Info,
		Warn,
		Error,
		Fatal
	};

	// Locatioon
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
		void log(MsgMeta&& meta, const string& format, const TArgs&... args);

		// level
		void setLevel(Level);
		Level getLevel()
		const;
	};

	// default logger
    void setDefaultLogger(unique_ptr<Logger>&& logger);
    Logger& getDefaultLogger();
	
	// macros
	#define LOGGER ::Logging::getDefaultLogger()
	#define LOG_TRACE(...)
	#define LOG_DEBUG(...)
	#define LOG_INFO(...)
	#define LOG_WARN(...)
	#define LOG_ERROR(...)
	#define LOG_FATAL(...)
}
```