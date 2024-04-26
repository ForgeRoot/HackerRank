#ifndef HRMLPARSER_LIb_QUERY_STATE_H_
#define HRMLPARSER_LIB_QUERY_STATE_H_

#include <query_handler.hpp>
#include <iostream>

class QueryState{
public:
    virtual bool handleToken(QueryHandler & handler, const char character) = 0;
    virtual ~QueryState() {};
};

    class NameQueryState : public QueryState{
    public:
        bool handleToken(QueryHandler & handler, const char character) override;
    };

    class DotQueryState: public QueryState{
    public:
        bool handleToken(QueryHandler & handler, const char character) override;
    };

    class WiggleQueryState: public QueryState{
    public:
        bool handleToken(QueryHandler & handler, const char character) override;
    };

    class AttributeQueryState: public QueryState{
    public:
        bool handleToken(QueryHandler & handler, const char character) override;
    };

#endif //HRMLPARSER_LIb_QUERY_STATE_H_