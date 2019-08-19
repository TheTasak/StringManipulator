#pragma once
#include "Utilities.hpp"
#include "String.hpp"
#include "File.hpp"
namespace Command
{
    std::string run(std::string);
    std::string checkFlag(std::string input)
    {
        std::size_t par = input.find(")");
        if(par != std::string::npos)
        {
            std::string s = input.substr(par+1);
            std::string flag = s;
            std::string flagtab[] = {FLAG_FILEINOUT_APP, FLAG_FILEINOUT_ATE, FLAG_FILEINOUT_TRUNC, FLAG_FILEINOUT_DEFAULT,
                                 FLAG_FILEIN_DEFAULT, FLAG_FILEOUT_APP, FLAG_FILEOUT_ATE, FLAG_FILEOUT_DEFAULT,
                                 FLAG_FILEOUT_TRUNC};
            std::size_t foundfirst = flag.find_first_of("?");
            std::size_t foundlast = flag.find_last_of("?");
            if(foundfirst != std::string::npos && foundlast != std::string::npos)
                flag.erase(foundfirst,foundlast);
            for(std::string s : flagtab)
                if(flag == s) return s;
            if(flag != "")
                return FLAG_WRONG;
            return FLAG_BLANK;
        }
        else
            return FLAG_BLANK;
    }
    std::string getFileName(std::string input)
    {
        std::size_t found = input.find("?");
        if(found == std::string::npos)
            return "";
        std::string s = input.substr(found+1);
        found = s.find("?");
        if(found == std::string::npos)
            return "";
        s.erase(found);
        return s;
    }
    std::string saveToFile(std::string s, std::string content = "")
    {
        if(checkFlag(s) == FLAG_FILEOUT_APP || checkFlag(s) == FLAG_FILEOUT_ATE || checkFlag(s) == FLAG_FILEOUT_TRUNC ||
           checkFlag(s) == FLAG_FILEOUT_DEFAULT || checkFlag(s) == FLAG_FILEINOUT_APP || checkFlag(s) == FLAG_FILEINOUT_TRUNC ||
           checkFlag(s) == FLAG_FILEINOUT_DEFAULT || checkFlag(s) == FLAG_FILEINOUT_ATE)
        {
            std::string filename = getFileName(s);
            if(!filename.empty())
                File::setFileText(filename,String::lastResult, checkFlag(s));
        }
        else if(content != "")
        {
            std::string text = "";
            if(content == "!")
                text = File::setFileText(s,String::lastResult);
            else if(content == "$")
                text = File::setFileText(s,String::container);
            else
                text = File::setFileText(s,content);
            return text;
        }
        return "";
    }
    void commandShow()
    {
        std::string file = File::getFileText(COMMAND_FILEPATH);
        Out::print(file);
    }
    template <typename T>
    void resultUpdate(std::string (*pointer)(T), std::string one)
    {
        if(one == LAST_RESULT && String::lastResult != "")
            String::lastResult = pointer(String::lastResult);
        else if(one == CONTAINER && String::container != "")
            String::lastResult = pointer(String::container);
        else
            String::lastResult = pointer(one);
    }
    template <typename T>
    void resultUpdate(std::string (*pointer)(T,T), std::string one, std::string two)
    {
        std::string o_1 = (one == LAST_RESULT && String::lastResult != "") ? String::lastResult : one;
        if(one == CONTAINER) o_1 = String::container;
        std::string o_2 = (two == LAST_RESULT && String::lastResult != "") ? String::lastResult : two;
        if(two == CONTAINER) o_2 = String::container;
        String::lastResult = pointer(o_1,o_2);
    }
    template <typename T>
    void resultUpdate(std::string (*pointer)(T,T,T), std::string one, std::string two,std::string three)
    {
        std::string o_1 = (one == LAST_RESULT && String::lastResult != "") ? String::lastResult : one;
        if(one == CONTAINER) o_1 = String::container;
        std::string o_2 = (two == LAST_RESULT && String::lastResult != "") ? String::lastResult : two;
        if(two == CONTAINER) o_2 = String::container;
        std::string o_3 = (three == LAST_RESULT && String::lastResult != "") ? String::lastResult : three;
        if(three == CONTAINER) o_3 = String::container;
        String::lastResult = pointer(o_1,o_2,o_3);
    }
    void command(std::string s,std::string type,int arguments = 1)
    {
        std::size_t beginstr = s.find_first_of("(");
        std::size_t endstr = s.find_last_of(")");
        std::string first;
        if(arguments == 1)
        {
            if(beginstr != std::string::npos && endstr != std::string::npos)
            {
                first = s.substr(beginstr+1, endstr - beginstr - 1);
                std::string (*pointer)(std::string);

                if(type == UPPER)               pointer = &String::to_upper;
                else if(type == LOWER)          pointer = &String::to_lower;
                else if(type == IS_DIGIT)       pointer = &String::is_digit;
                else if(type == IS_PRIME)       pointer = &String::is_prime;
                else if(type == REVERSE)        pointer = &String::reverse;
                else if(type == FILE_GET)       pointer = &File::getFileText;
                else if(type == LEN)            pointer = &String::length;
                else if(type == TO_OPPOSITE)    pointer = &String::to_opposite;
                else if(type == FACTORIAL)      pointer = &String::factorial;
                else if(type == PASSWORD_GEN)   pointer = &String::passwordGen;
                else if(type == TEXT_GEN)       pointer = &String::textGen;
                else if(type == SET_CONTAINER)  pointer = &String::setContainer;
                else if(type == WORD_COUNT)     pointer = &String::wordCount;
                else if(type == TO_ASCII)       pointer = &String::to_ascii;
                else if(type == TO_TEXT)        pointer = &String::to_text;
                else if(type == RUN)            pointer = &Command::run;
                else if(type == REMOVE_NUM)     pointer = &String::removenumbers;
                else if(type == REMOVE_TEXT)    pointer = &String::removetext;
                else                            pointer = nullptr;

                if(checkFlag(s) == FLAG_FILEIN_DEFAULT || checkFlag(s) == FLAG_FILEINOUT_APP || checkFlag(s) == FLAG_FILEINOUT_ATE ||
                   checkFlag(s) == FLAG_FILEINOUT_DEFAULT || checkFlag(s) == FLAG_FILEINOUT_TRUNC)
                    first = File::getFileText(first);
                resultUpdate(pointer,first);
                saveToFile(s);
                Out::print(String::lastResult);
            }
            else
                Out::print(ERROR_NOTSPECIFIED);
        }
        else if(arguments == 2)
        {
            std::size_t comma = s.find(",");
            if(comma != std::string::npos && beginstr != std::string::npos && endstr != std::string::npos)
            {
                first = s.substr(beginstr+1, comma - beginstr - 1);
                std::string second = s.substr(comma+1, endstr - comma - 1);
                std::string (*pointer)(std::string,std::string);

                if(type == MULTIPLY_CHAR)               pointer = &String::multiply;
                else if(type == REMOVE)                 pointer = &String::remove;
                else if(type == LIST_PRIME)             pointer = &String::listPrime;
                else if(type == FILE_SAVE)              pointer = &Command::saveToFile;
                else if(type == COUNT)                  pointer = &String::count;
                else if(type == ROOT)                   pointer = &String::root;
                else if(type == RANDOM)                 pointer = &String::random;
                else if(type == SPLIT)                  pointer = &String::split;
                else if(type == ROTATE)                 pointer = &String::rotate;
                else if(type == REMOVE_NTH)             pointer = &String::removenth;
                else                                    pointer = nullptr;

                if(checkFlag(s) == FLAG_FILEIN_DEFAULT || checkFlag(s) == FLAG_FILEINOUT_APP || checkFlag(s) == FLAG_FILEINOUT_ATE ||
                   checkFlag(s) == FLAG_FILEINOUT_DEFAULT || checkFlag(s) == FLAG_FILEINOUT_TRUNC)
                    first = File::getFileText(first);
                resultUpdate(pointer,first,second);
                saveToFile(s);
                Out::print(String::lastResult);
            }
            else
                Out::print(ERROR_NOTSPECIFIED);
        }
        else if(arguments == 3)
        {
            std::size_t comma = s.find(",");
            if(comma != std::string::npos)
            {
                std::size_t comma_sec = s.find(",", comma+1);
                std::string second,third;
                std::string (*pointer)(std::string,std::string,std::string);
                if(comma_sec != std::string::npos && beginstr != std::string::npos && endstr != std::string::npos)
                {
                    first = s.substr(beginstr+1, comma - beginstr - 1);
                    second = s.substr(comma+1, comma_sec - comma - 1);
                    third = s.substr(comma_sec+1, endstr - comma_sec - 1);

                    if(type == REPLACE)                 pointer = &String::replace;
                    else if(type == RANGE)              pointer = &String::range;
                    else if(type == ADD_CHAR)           pointer = &String::addChar;
                    else if(type == REMOVE_RANGE)       pointer = &String::removerange;
                    else if(type == TO_BASE)            pointer = &String::toBase;
                    else                                pointer = nullptr;

                    if(checkFlag(s) == FLAG_FILEIN_DEFAULT || checkFlag(s) == FLAG_FILEINOUT_APP || checkFlag(s) == FLAG_FILEINOUT_ATE ||
                       checkFlag(s) == FLAG_FILEINOUT_DEFAULT || checkFlag(s) == FLAG_FILEINOUT_TRUNC)
                        first = File::getFileText(first);
                    resultUpdate(pointer,first,second,third);
                    saveToFile(s);
                    Out::print(String::lastResult);
                }
                else
                    Out::print(ERROR_NOTSPECIFIED);
            }
            else
                Out::print(ERROR_NOTSPECIFIED);
        }
        else
            Out::print(ERROR_NOTSPECIFIED);
    }
    void checkCommand(std::string s)
    {
        using namespace Command;

        std::size_t bracket = s.find("(");
        std::string str = (bracket != std::string::npos) ? s.substr(0,bracket) : s;
        if(str == FILE_GET)                 command(s,FILE_GET);
        else if(str == ADD_CHAR)            command(s,ADD_CHAR,3);
        else if(str == FILE_SAVE)           command(s,FILE_SAVE,2);
        else if(str == MULTIPLY_CHAR)       command(s,MULTIPLY_CHAR,2);
        else if(str == REVERSE)             command(s,REVERSE);
        else if(str == REMOVE)              command(s,REMOVE,2);
        else if(str == REPLACE)             command(s,REPLACE,3);
        else if(str == UPPER)               command(s,UPPER);
        else if(str == LOWER)               command(s,LOWER);
        else if(str == IS_DIGIT)            command(s,IS_DIGIT);
        else if(str == IS_PRIME)            command(s,IS_PRIME);
        else if(str == LIST_PRIME)          command(s,LIST_PRIME,2);
        else if(str == LEN)                 command(s,LEN);
        else if(str == RANGE)               command(s,RANGE,3);
        else if(str == COUNT)               command(s,COUNT,2);
        else if(str == ROOT)                command(s,ROOT,2);
        else if(str == RANDOM)              command(s,RANDOM,2);
        else if(str == TO_OPPOSITE)         command(s,TO_OPPOSITE);
        else if(str == FACTORIAL)           command(s,FACTORIAL);
        else if(str == PASSWORD_GEN)        command(s,PASSWORD_GEN);
        else if(str == TEXT_GEN)            command(s,TEXT_GEN);
        else if(str == TO_BASE)             command(s,TO_BASE,3);
        else if(str == RUN)                 command(s,RUN);
        else if(str == HELP)                commandShow();
        else if(str == CLEAR_ACC)           String::accumulator = 0;
        else if(str == SHOW_LAST)           Out::print(String::lastResult);
        else if(str == SHOW_ACC)            Out::print(String::accumulator);
        else if(str == CLEAR_LAST)          String::lastResult = "";
        else if(str == SET_CONTAINER)       command(s,SET_CONTAINER);
        else if(str == WORD_COUNT)          command(s,WORD_COUNT);
        else if(str == SPLIT)               command(s,SPLIT,2);
        else if(str == ROTATE)              command(s,ROTATE,2);
        else if(str == TO_ASCII)            command(s,TO_ASCII);
        else if(str == TO_TEXT)             command(s,TO_TEXT);
        else if(str == REMOVE_TEXT)         command(s,REMOVE_TEXT);
        else if(str == REMOVE_NUM)          command(s,REMOVE_NUM);
        else if(str == REMOVE_RANGE)        command(s,REMOVE_RANGE,3);
        else if(str == REMOVE_NTH)          command(s,REMOVE_NTH,2);
        else if(str == CLEAR_CONTAINER)     String::container = "";
        else if(str == SHOW_CONTAINER)      Out::print(String::container);
        //else if(str == LIST_DIR)          Out::print(String::ls());
        else                                Out::print(ERROR_COMMAND_NOT_DEFINED);
    }
    std::string run(const std::string s)
    {
        std::vector<std::string> vec;
        int previous = 0;
        std::string result = "";
        for(unsigned int i = 0; i < s.size(); i++)
        {
            if(s[i] == ';')
            {
                std::string push = s.substr(previous,i-previous);
                if(push[0] == '\n' || push[0] == ' ') push.erase(0,1);
                vec.push_back(push);
                previous = i+1;
            }
        }
        for(unsigned int i = 0; i < vec.size(); i++)
        {
            Out::print(vec.at(i)+ ": ");
            checkCommand(vec.at(i));
            Out::print("",true);
        }
        return result;
    }
}
