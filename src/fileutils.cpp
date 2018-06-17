#include "fileutils.h"
#ifdef _MSC_VER
#include <dirent_windows.h>
#else
#include <dirent.h>
#endif
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

bool hasFileEnding(const char *filename, const char *end) {
    size_t len = std::strlen(filename);
    size_t endLen = std::strlen(end);

    if (len <= endLen)
        return false;

    size_t offset = len - endLen;

    return std::strcmp(filename + offset, end) == 0;
}

void getDirectoryFiles(const char *dir, bool recursive, std::vector<std::string> &out_filenames) {
    DIR* d = opendir(dir);

    if (d == nullptr)
        return;

    struct dirent* ent;

    std::string strDir(dir);

    while ((ent = readdir(d)) != nullptr) {
        std::string fpath(ent->d_name);

        if (fpath == "." || fpath == "..")
            continue;

        std::string fullpath = strDir + std::string("/") + fpath;

        FileType ft = GetFileType(fullpath.c_str());

        switch (ft) {
        case FT_FILE:
            out_filenames.push_back(fullpath);
            break;
        case FT_DIR:
            if (recursive)
                getDirectoryFiles(fullpath.c_str(), recursive, out_filenames);
            break;
        case FT_UNKNOWN:
        case FT_NOT_FOUND:
            break;
        }
    }

    closedir(d);
}

FileType GetFileType(const char *path) {
    struct stat path_stat;
    if (stat(path, &path_stat) != 0)
        return FT_NOT_FOUND;

    if (S_ISREG(path_stat.st_mode))
        return FT_FILE;

    if (S_ISDIR(path_stat.st_mode))
        return FT_DIR;

    return FT_UNKNOWN;
}

std::vector<std::string> getFileNames(const char * dir, bool recursive, const std::string extension)
{
    std::vector<std::string> filenames;
    std::vector<std::string> objFiles;
    FileType ft = GetFileType(dir);
    getDirectoryFiles(dir, false, filenames);
    for (const std::string& abspath : filenames) {
        ft = GetFileType(abspath.c_str());

        if (ft != FT_FILE)
            continue;

        if (hasFileEnding(abspath.c_str(), extension.c_str())) {
            objFiles.push_back(abspath);
        }
    }
    return objFiles;
}

bool isSpaces(std::string s)
{
    std::string spaces;
    for(int i=0; i<s.size(); i++)
        spaces.push_back(' ');

    if(s.compare(spaces)==0)
        return true;
    return false;
}

std::string AddFilePath(const char* in_filePath, const char* in_fileName)
{
    std::string filePath = in_filePath;
    std::string fileName = in_fileName;

    // get all backslashes and replace by forward slashes
    std::replace(filePath.begin(),filePath.end(),'\\','/');
    std::replace(fileName.begin(),fileName.end(),'\\','/');

    //we need to know if fileName is absolute or
    filePath = filePath + fileName;

    return filePath;
}
