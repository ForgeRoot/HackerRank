#include <query.hpp>

Query::Query(): current_state_(new NameQueryState){}

Query::~Query() {
    delete current_state_;
}

void Query::handleInput(const std::string& hrml_line){
    for (size_t i = 0; i < hrml_line.size(); ){
        const char character = hrml_line[i];
        bool processed = current_state_->handleToken(*this, character);
        if (processed)
            ++i;
    }
}

void Query::commitNameToNames(){
    names_.push_back(name_);
    name_.clear();
}

void Query::addCharToName(const char & character){
    name_ += character;
}

void Query::addCharToAttribute(const char & character){
    attribute_ += character;
}


void Query::changeState(QueryState* new_state){
    delete current_state_;
    current_state_ = new_state;
}

void Query::printQuery(){
    for (const auto & name: names_){
        std::cout << name << "." ;
    }
    std::cout << "~" << attribute_ << std::endl;
}

std::string Query::getAttribute(const std::vector<std::unique_ptr<Tag>>& stored_tags){
    for (size_t i = 0; i < names_.size() && i < stored_tags.size(); ++i) {
            if (names_[i] == stored_tags[i]->getName()) {
                if (i == names_.size() - 1) {
                    return stored_tags[i]->getAttribute(attribute_);
                }
            }
        }

    return ""; 
}