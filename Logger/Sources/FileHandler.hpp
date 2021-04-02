//
//  FileHandler.hpp
//  Logger
//
//  Created by Francesco Gavioli on 16/03/21.
//

#ifndef FileHandler_hpp
#define FileHandler_hpp

#include <stdio.h>
#include <string>
#include "Utility.hpp"

namespace FileHandlerSpace
{
    class FileHandler
    {
    private:
        const UtilitySpace::Utility& utils;
        char const* fileName;
        char const* folderName;
        void SetFileName();
        void SetFolderName();
    public:
        ~FileHandler();
        FileHandler();
        FileHandler(char const* fileName, char const* folderName,const UtilitySpace::Utility& utils);
        // different method needed : write to file, create a folder,
        // change file, get file size (if too big change folder)
        char const* GetFileName();
        char const* GetFolderName();
        std::ofstream GetFileStream();
    };
}
#endif /* FileHandler_hpp */
