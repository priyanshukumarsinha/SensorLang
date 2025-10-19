/*
while (not end of input) {
    skipWhitespace();
    if (comment) readComment();
    else if (symbol) handleSymbol();
    else if (letter) readIdentifier();
    else if (digit) readInteger();
    else if (timestampPattern) readTimestamp();
    else markInvalid();
}
*/
#include<vector>
#include"token.h"
#ifndef LEXER_H
#define LEXER_H

class Lexer{
private:
    std::string input;
    size_t pos;
    int line;
    void skipWhitespace();
    char peek();
    std::string readIdentifier();
    bool isKeyword(std::string &id);
    std::string readInteger();
    std::string readTimeStamp();
    bool isSymbol();
    std::string readComment();
    
public:
    Lexer(const std::string &text);
    std::vector<Token> tokenize();
};


#endif