#ifndef HRMLPARSER_LIB_TAG_H_
#define HRMLPARSER_LIB_TAG_H_

#include <unordered_map>
#include <string>
#include <iostream>
#include <sstream>

#include <tag_handler.hpp>
#include <tag_state.hpp>

class Tag : public TagHandler {
public:
    Tag();
    ~Tag();
    void handleInput(const std::string& hrml_line);
    void setName(const std::string& name) override;
    void setKey(const std::string& key) override;
    void setValue(const std::string& value) override;
    void commitAttribute() override;
    void changeState(TagState* new_state);

    void printTag();

    std::string getName() const;
    std::string getAttribute(std::string key) const;

private:
    std::string name_;
    std::unordered_map<std::string, std::string> attributes_;
    TagState* current_state_;
    std::string current_key_;
    std::string current_value_;
};

#endif // HRMLPARSER_LIB_TAG_H_