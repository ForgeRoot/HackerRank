#include <parser.hpp>

Parser::Parser(){};

void Parser::createHRMLTags(const std::vector<std::string> hrml_lines_content){
        for (const std::string& hrml_line: hrml_lines_content){
        tags_
        
    }
}

HRMLParserContent Parser::getHRMLParserContent(const std::vector<std::string> contents){
    std::string first_line = contents[0];
    std::vector<std::string> second_part(contents.begin() + 1, contents.end());
    size_t hrml_lines = getCountOfHrmlLines(first_line);
    return splitOriginalContentsIntoHRMLParserContent(second_part, hrml_lines);
}

    size_t Parser::getCountOfHrmlLines(std::string first_line){
        size_t HRML_lines_count;
        std::istringstream iss(first_line);
        iss >> HRML_lines_count;
        return HRML_lines_count;
    }

    HRMLParserContent Parser::splitOriginalContentsIntoHRMLParserContent(const std::vector<std::string> contents, const size_t hrml_lines){
        HRMLParserContent return_parser_content;
        return_parser_content.HRML_lines.assign(contents.begin(), contents.begin() + hrml_lines);
        return_parser_content.Query_lines.assign(contents.begin() + hrml_lines, contents.end());
        return return_parser_content;
    }
