#include <tag.hpp>

Tag::Tag(): current_state_(new InitialTagState) {}

Tag::~Tag() {
    delete current_state_;
}

void Tag::handleInput(const std::string& hrml_line){
    std::istringstream iss(hrml_line);
    std::string token;
    while(iss >> token) {
        current_state_->handleToken(*this, token);
    }
}

void Tag::setKey(const std::string& key) {
    current_key_ = key;
}

void Tag::setValue(const std::string& value) {
    current_value_ = value;
}

void Tag::commitAttribute() {
    attributes_[current_key_] = current_value_;
}

void Tag::changeState(TagState* new_state){
    delete current_state_;
    current_state_ = new_state;
}


