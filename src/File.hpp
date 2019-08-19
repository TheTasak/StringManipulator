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
    std::string setFileText(std::string filename, std::string content, std::string type = FLAG_FILEOUT_DEFAULT)
    {
        std::fstream file;
        if(type == FLAG_FILEOUT_DEFAULT || type == FLAG_FILEOUT_TRUNC || FLAG_FILEINOUT_TRUNC || FLAG_FILEINOUT_DEFAULT)
            file.open(filename, std::fstream::out | std::fstream::trunc);
        else if(type == FLAG_FILEOUT_APP || type == FLAG_FILEINOUT_APP)
            file.open(filename, std::fstream::out | std::fstream::app);
        else if(type == FLAG_FILEOUT_ATE || type == FLAG_FILEINOUT_ATE)
            file.open(filename, std::fstream::out | std::fstream::ate);

        if(file.fail() || !file.is_open())
            return ERROR_OPENFILE;
        file << content;
        return "";
    }
    std::string setGetFileText(std::string filename, std::string content, std::string type = FLAG_FILEINOUT_DEFAULT)
    {
        if(setFileText(filename,content,type) != "")
            return ERROR_OPENFILE;
        return getFileText(filename);
    }
}
