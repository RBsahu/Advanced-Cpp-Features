/*
Logger Manager – Singleton Design Pattern
Key Design Points

Private Constructor
Deleted Copy Constructor & Assignment Operator
Static Instance Method
Thread Safe Logging
Lazy Initialization (created when first used)

Logger must:
Have only one instance
Be thread-safe
Avoid race condition during initialization
Be accessible globally
Support different log levels
Write to file / console safely

This implementation ensures that only one instance of the Logger class exists 
throughout the application, providing a centralized logging mechanism. 
The use of mutex ensures thread safety when multiple threads are logging messages
simultaneously. The log level can be set to filter messages based on their severity.
*/

#include <iostream>
#include <fstream>
#include <mutex>
#include <string>
#include <ctime>

using namespace std;

enum class LogLevel
{
    INFO,
    WARN,
    ERROR
};

class Logger
{
private:
    mutex mtx;
    ofstream logFile;
    LogLevel currentLevel;

    Logger() : currentLevel(LogLevel::INFO)
    {
        logFile.open("log.txt", ios::app);
    }

    string getLogLevelString(LogLevel level)
    {
        switch (level)
        {
        case LogLevel::INFO:  return "INFO";
        case LogLevel::WARN:  return "WARN";
        case LogLevel::ERROR: return "ERROR";
        }
        return "UNKNOWN";
    }

    string getCurrentTime()
    {
        time_t now = time(0);
        char buf[26];

#ifdef _WIN32
        ctime_s(buf, sizeof(buf), &now);
#else
        ctime_r(&now, buf);
#endif

        return string(buf);
    }
public:
    static Logger& getInstance()
    {
        static Logger instance;
        return instance;
    }

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    void setLogLevel(LogLevel level)
    {
        currentLevel = level;
    }

    void log(LogLevel level, const string& message)
    {
        if (level < currentLevel)
            return;

        lock_guard<mutex> lock(mtx);
        logFile << getCurrentTime()
            << " [" << getLogLevelString(level) << "] "
            << message << endl;
    }
};

int main()
{
    Logger& logger = Logger::getInstance();

    logger.setLogLevel(LogLevel::WARN);

    logger.log(LogLevel::INFO, "This is Info Message");
    logger.log(LogLevel::WARN, "This is Warning Message");
    logger.log(LogLevel::ERROR, "This is Error Message");

    return 0;
}