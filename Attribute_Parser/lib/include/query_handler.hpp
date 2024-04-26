#ifndef HRMLPARSER_LIB_QUERY_HANDLER_H_
#define HRMLPARSER_LIB_QUERY_HANDLER_H_

#include<string>


class QueryState;

class QueryHandler{
public:
    virtual void commitNameToNames() = 0;
    virtual void addCharToName(const char& character) = 0;
    virtual void addCharToAttribute(const char& character) = 0;
    virtual void changeState(QueryState* new_state) = 0;
    virtual ~QueryHandler() {}
};

#endif //HRMLPARSER_LIB_QUERY_HANDLER_H_