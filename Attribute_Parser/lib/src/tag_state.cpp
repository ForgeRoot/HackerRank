#include <tag_state.hpp>

void InitialTagState::handleToken(TagHandler& handler, const std::string& token){
    if (token[0] == '<'){
        handler.setKey(token.substr(1));
        handler.changeState(new KeyTagState());
    }
}

void KeyTagState::handleToken(TagHandler& handler, const std::string& token){
    if (token == "="){
        handler.changeState(new ValueTagState());
    }
}

void ValueTagState::handleToken(TagHandler& handler, const std::string& token){
    handler.setValue(token);
    handler.commitAttribute();
    handler.changeState(new InitialTagState());
}