#ifndef HRMLPARSER_LIB_PARSER_H_
#define HRMLPARSER_LIB_PARSER_H_

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <format>
#include <tag.hpp>


struct HRMLParserContent {
    std::vector<std::string> HRML_lines;
    std::vector<std::string> Query_lines;
};


class Parser{
public:
    Parser(); 

    void createHRMLTags(const std::vector<std::string> hrml_lines_content);

private:
    std::vector<Tag> tags_;

    HRMLParserContent getHRMLParserContent(const std::vector<std::string> contents);
    HRMLParserContent splitOriginalContentsIntoHRMLParserContent(const std::vector<std::string> contents, const size_t hrml_lines);
    size_t getCountOfHrmlLines(std::string first_line);

};

#endif //HRMLPARSER_LIB_PARSER_H_