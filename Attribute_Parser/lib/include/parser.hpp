#ifndef HRMLPARSER_LIB_PARSER_H_
#define HRMLPARSER_LIB_PARSER_H_

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <format>
#include <tag.hpp>
#include <query.hpp>
#include <algorithm>


struct HRMLParserContent {
    std::vector<std::string> HRML_lines;
    std::vector<std::string> Query_lines;
};


class Parser{
public:
    Parser(); 

    void parse(const std::vector<std::string> contents);

private:
    std::vector<std::unique_ptr<Tag>> tags_;
    std::vector<std::unique_ptr<Query>> queries_;
    void iterateThroughHRMLLines(const std::vector<std::string> hrml_lines_content);
    void iterateThroughQueryLines(const std::vector<std::string> query_lines_content);
    void checkTagsVector(const std::vector<std::string> hrml_lines_content);
    void createHRMLTags(const std::vector<std::string> hrml_lines_content);
    void checkNameInTags(const std::string name);
    void createQuery(const std::string query_line);
    void parseQueries();
    std::string getClosingTagName(const std::string hrml_line);
    HRMLParserContent getHRMLParserContent(const std::vector<std::string> contents);
    HRMLParserContent splitOriginalContentsIntoHRMLParserContent(const std::vector<std::string> contents, const size_t hrml_lines);
    size_t getCountOfHrmlLines(std::string first_line);

};

#endif //HRMLPARSER_LIB_PARSER_H_