//
//  FileHandler.cpp
//  Logger
//
//  Created by Francesco Gavioli on 16/03/21.
//

#include "FileHandler.hpp"
#include <iostream>
#include <fstream>

FileHandlerSpace::FileHandler::FileHandler(char const* fileName, char const* folderName, const UtilitySpace::Utility& utils)
    : fileName(fileName), utils(utils)
{
#ifdef __APPLE__
    this->folderName = "/Users/francescogavioli/";
#endif
#ifdef _WIN32
    this->folderName = "C:\\tmp";
#endif
    std::cout << "File handler constructor" << std::endl;
}

FileHandlerSpace::FileHandler::~FileHandler()
{
    std::cout << "File handler destructor" << std::endl;
}

const char* FileHandlerSpace::FileHandler::GetFileName()
{
    return this->fileName;
}

const char* FileHandlerSpace::FileHandler::GetFolderName()
{
    return this->folderName;
}

std::ofstream FileHandlerSpace::FileHandler::GetFileStream()
{
    std::string fileName(this->GetFileName());
    std::string folderName(this->GetFolderName());
    std::ofstream outFile(folderName + fileName);
    return outFile;
}

