#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum class TokenType{
    KEYWORD,
    IDENTIFIER,
    INTEGER_LITERAL,
    SYMBOL,
    COMMENT,
    INVALID,
    EOF_TOKEN
};

// structure of token
struct Token{
    TokenType type;
    // since we don't need to add or subtract, we can just keep it as string
    // or else we could have used union to minimize data wastage
    std::string value;
    int line;
};

#endif