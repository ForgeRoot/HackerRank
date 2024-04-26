#include <tag.hpp>

Tag::Tag(): current_state_(new NameTagState) {}

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

void Tag::setName(const std::string& name){
    name_ = name;
}

void Tag::setValue(const std::string& value) {
    current_value_ = value;
}

void Tag::commitAttribute() {
    attributes_[current_key_] = current_value_;
    //print the attributes
    
}

void Tag::changeState(TagState* new_state){
    delete current_state_;
    current_state_ = new_state;
}

void Tag::printTag(){
    if (name_.empty() && attributes_.empty()) {
        std::cout << "Empty tag detected." << std::endl;
        return;
    }
    std::cout << "name: " << name_ << std::endl;
    std::cout << "attributes: " << std::endl;
    for (const auto& attribute: attributes_){
        std::cout << "\tKey: " << attribute.first << ", Value: " << attribute.second << std::endl;
    }
}

std::string Tag::getName() const{
    return name_;
}

std::string Tag::getAttribute(std::string key) const{
    auto it = attributes_.find(key);
    if (it != attributes_.end()) {
        return it->second;
    }
    return "Not Found!";
}
