
#ifndef HRMLPARSER_LIB_FILE_READER_H_
#define HRMLPARSER_LIB_FILE_READER_H_

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <format>

//  = "C:/Code/HackerRank/Attribute_Parser/Test_input/input.txt"

class FileReader{
public:
    FileReader(std::string input_filename);

    void loadLinesFromFile();

    std::vector<std::string> getContents() const;
private:
    std::string input_filename_;
    std::ifstream file_stream_;
    std::vector<std::string> contents_;


    void openFileStream();
    void loadContentsFromOpenFileStream();
    void closeFileStream();
};

#endif //HRMLPARSER_LIB_FILE_READER_H_