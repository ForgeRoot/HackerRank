#include <tag_state.hpp>

void NameTagState::handleToken(TagHandler& handler, const std::string& token){
    if (token[0] == '<' && token[1] != '/'){
        handler.setName(token.substr(1));
        handler.changeState(new KeyTagState());
    }
}

void KeyTagState::handleToken(TagHandler& handler, const std::string& token){
    handler.setKey(token);
    handler.changeState(new EqualTagState());
}

void EqualTagState::handleToken(TagHandler& handler, const std::string& token){
    if (token == "="){
        handler.changeState(new ValueTagState());
    }
}

void ValueTagState::handleToken(TagHandler& handler, const std::string& token){
    if (token.back() == '>'){
        handler.setValue(token.substr(0, token.size() - 1));
        handler.commitAttribute();
        handler.changeState(new NameTagState());
    } else {
        handler.setValue(token);
        handler.commitAttribute();
        handler.changeState(new KeyTagState());
    }
}