#ifndef HRMLPARSER_LIb_QUERY_H_
#define HRMLPARSER_LIB_QUERY_H_

#include <vector>
#include <string>
#include <query_handler.hpp>
#include <query_state.hpp>
#include <iostream>
#include <tag.hpp>


class Query : public QueryHandler{ 
public:
    Query();
    ~Query();
    void handleInput(const std::string& query_line);
    void commitNameToNames() override;
    void addCharToName(const char& character) override;
    void addCharToAttribute(const char& character) override;

    void changeState(QueryState* new_state) override;

    void printQuery();

    std::string getAttribute(const std::vector<std::unique_ptr<Tag>>& stored_tags);
private:
    std::vector<std::string> names_;
    std::string name_;
    std::string attribute_;

    QueryState* current_state_;


};

#endif //HRMLPARSER_LIB_QUERY_H_