#pragma once
#include "Utilities.hpp"

#include <fstream>

namespace File
{
    std::string getFileText(std::string filename)
    {
        std::fstream file;
        file.open(filename, std::fstream::in);
        if(file.fail() || !file.is_open())
            return ERROR_OPENFILE;
        std::string result;
        while(!file.eof())
        {
            std::string buf = "";
            std::getline(file,buf);
            result += std::string(buf + "\n");
        }
        result.erase(result.end()-1);
        file.close();
        return result;
    }
    std::string setFileText(std::string filename, std::string content, int type = FILE_TRUNC)
    {
        std::fstream file;
        if(type == FILE_TRUNC)
            file.open(filename, std::fstream::out | std::fstream::trunc);
        else if(type == FILE_APP)
            file.open(filename, std::fstream::out | std::fstream::app);
        else if(type == FILE_ATE)
            file.open(filename, std::fstream::out | std::fstream::ate);

        if(file.fail() || !file.is_open())
            return ERROR_OPENFILE;
        file << content;
        return "";
    }
    std::string setGetFileText(std::string filename, std::string content)
    {
        if(setFileText(filename,content) != "")
            return ERROR_OPENFILE;
        return getFileText(filename);
    }
}
