//
//  Log.hpp
//  Logger
//
//  Created by Francesco Gavioli on 15/03/21.
//

#ifndef Log_hpp
#define Log_hpp

#include <stdio.h>
#include <string>
#include <ctime>
#include <fstream>
#include "FileHandler.hpp"

// globals
enum LogLevel
{
    ALL = 0,
    INFO = 1,
    TRACE = 2,
    ERROR = 3
};

// header
namespace LogSpace
{
    template <typename T>
    class Log
    {
    private:
        FileHandlerSpace::FileHandler& fh;
        std::string input;
        LogLevel type;
        static int16_t logCount;
    private:
        std::string GetLevel(const LogLevel level);
        tm* GetCurrentTime();
        
    public:
        Log(FileHandlerSpace::FileHandler& fh);
        ~Log();
        void Print(T input, LogLevel level);
    };
}

// class implementations
template<typename T>
int16_t LogSpace::Log<T>::logCount = 0;

template<typename T>
std::string LogSpace::Log<T>::GetLevel(const LogLevel lvl)
{
    switch(lvl)
    {
        case 0:
            return "ALL";
        case 1:
            return "INFO";
        case 2:
            return "TRACE";
        case 3:
            return "ERROR";
        default:
            return "UNKNOWN";
    }
}

template<typename T>
tm* LogSpace::Log<T>::GetCurrentTime()
{
    time_t now = time(0);
    tm* localtm = localtime(&now);
    return localtm;
}

// implementation
template<typename T>
LogSpace::Log<T>::Log(FileHandlerSpace::FileHandler& fh)
    : fh(fh)
{
    
    // initialize related services
    std::cout << "constructor" << std::endl;
}

template<typename T>
LogSpace::Log<T>::~Log()
{
    std::cout << "destructor" << std::endl;
}

template<typename T>
void LogSpace::Log<T>::Print(T input, LogLevel level)
{
    // level conversion
    std::string lvl = this->GetLevel(level);
    
    // get time
    tm* localtm = this->GetCurrentTime();
    
    // get output file stream
    std::ofstream output = fh.GetFileStream();
    
    // printing
    output << "LOG NR : " << LogSpace::Log<T>::logCount << std::endl;
    output << "DATETIME : " << asctime(localtm);
    output << "LEVEL : " << lvl << " , MESSAGE : " << input << std::endl;
    LogSpace::Log<T>::logCount++;
}

#endif /* Log_hpp */


