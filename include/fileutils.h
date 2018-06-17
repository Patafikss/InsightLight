#ifndef FILEUTILS_H
#define FILEUTILS_H
#include <vector>
#include <iostream>

enum FileType {
    FT_FILE = 0,
    FT_DIR = 1,
    FT_UNKNOWN = 2,
    FT_NOT_FOUND = 3,
};

bool hasFileEnding(const char* filename, const char* end);
FileType GetFileType(const char* path);
//Writes every file names in the ou_filenames vector
void getDirectoryFiles(const char* dir, bool recursive, std::vector<std::string>& out_filenames);

//Compare the given string against just spaces, true if there is only spaces
bool isSpaces(std::string s);

//Returns the file names of files having the extension "extension"
std::vector<std::string> getFileNames(const char * dir, bool recursive, const std::string extension = ".obj");
std::string AddFilePath(const char* in_filePath, const char* in_fileName);
#endif // FILEUTILS_H
