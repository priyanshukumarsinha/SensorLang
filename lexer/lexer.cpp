#include<lexer.h>
#include<vector>


Lexer::Lexer(const std::string& text){
    this->input = text;
    this->pos = 0;
    this->line = 1;
}

std::vector<Token> Lexer::tokenize(){

    // list of all tokens
    std::vector<Token> tokens;
    // Token({type, value, line})

    // we check each character until we reach EOF
    // i.e until pos < input.size()

    while(this->pos < this->input.size()){

    }

    // when we reach EOF
    // add a token representing EOF to the list of tokens
    tokens.push_back({TokenType::EOF_TOKEN,"",this->line });

    // returns list of tokens
    return tokens;
}