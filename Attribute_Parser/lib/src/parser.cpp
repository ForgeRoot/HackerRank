#include <parser.hpp>

Parser::Parser(){};

void Parser::parse(const std::vector<std::string> contents){
    HRMLParserContent hrml_content = getHRMLParserContent(contents);

    iterateThroughHRMLLines(hrml_content.HRML_lines);
    for (auto& tag: tags_){
        tag->printTag();   
    }

}

void Parser::iterateThroughHRMLLines(const std::vector<std::string> hrml_lines_content){
    const std::vector<std::string> hrml_open_lines(hrml_lines_content.begin(), hrml_lines_content.begin() + hrml_lines_content.size() / 2);
    const std::vector<std::string> hrml_close_lines(hrml_lines_content.begin() + hrml_lines_content.size() / 2, hrml_lines_content.end());
    createHRMLTags(hrml_open_lines);
    checkTagsVector(hrml_close_lines);
}

    void Parser::checkTagsVector(const std::vector<std::string> hrml_lines_content){
        for (const std::string& hrml_line: hrml_lines_content){
            std::string name = getClosingTagName(hrml_line);
            checkNameInTags(name);
        }
    }

        std::string Parser::getClosingTagName(const std::string hrml_line){
            std::string name = hrml_line.substr(2, hrml_line.size() - 3);
            return name;
        }

        void Parser::checkNameInTags(const std::string name){
            bool is_name_in_tags = false;
            for (auto & tag: tags_){
                if (tag->getName() == name){
                    is_name_in_tags = true;
                    break;
                }
            }
            if (!is_name_in_tags){
                std::cout << "No matching tag found for closing tag: " << name << std::endl;
            }
        }


    void Parser::createHRMLTags(const std::vector<std::string> hrml_lines_content){
        for (const std::string& hrml_line: hrml_lines_content){
            auto tag = std::make_unique<Tag>(); 
            tag->handleInput(hrml_line);
            tags_.push_back(std::move(tag));
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
