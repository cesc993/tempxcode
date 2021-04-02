//
//  main.cpp
//  Logger
//
//  Created by Francesco Gavioli on 15/03/21.
//

#include <iostream>
#include "Utility.hpp"
#include "Log.hpp"


int main(int argc, const char * argv[]) {
    
    // use file handler
    char logFile[] = "log.txt";
    char logFolder[] = "logFolder";
    const UtilitySpace::Utility utils;
    FileHandlerSpace::FileHandler fh(logFile, logFolder, utils);
    
    // log operations
    LogSpace::Log<const char*> logging(fh);
    logging.Print("qrqrwqwor125125152", INFO);
    return 0;
}
