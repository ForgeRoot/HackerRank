#include <query_state.hpp>

bool NameQueryState::handleToken(QueryHandler & handler, const char character){
    if (character == '.') {
        handler.changeState(new DotQueryState());
        return false;
    } else if (character == '~') {
        handler.changeState(new WiggleQueryState);
        return false;
    } else {
        handler.addCharToName(character);
        return true;
    }
}

bool DotQueryState::handleToken(QueryHandler & handler, const char character){
    handler.commitNameToNames();
    handler.changeState(new NameQueryState);
    return true;
}

bool WiggleQueryState::handleToken(QueryHandler & handler, const char character){
    handler.commitNameToNames();
    handler.changeState(new AttributeQueryState ());
    return true;
}

bool AttributeQueryState::handleToken(QueryHandler & handler, const char character){
    handler.addCharToAttribute(character);
    return true;
}