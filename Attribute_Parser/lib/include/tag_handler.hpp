#ifndef HRMLPARSER_LIB_TAG_HANDLER_H_
#define HRMLPARSER_LIB_TAG_HANDLER_H_

#include <string>

class TagState;

class TagHandler {
public:
    virtual void setName(const std::string& name) = 0;
    virtual void setKey(const std::string& key) = 0;
    virtual void setValue(const std::string& value) = 0;
    virtual void commitAttribute() = 0;
    virtual void changeState(TagState* new_state) = 0;
    virtual ~TagHandler() {}
};

#endif //HRMLPARSER_LIB_TAG_HANDLER_H_