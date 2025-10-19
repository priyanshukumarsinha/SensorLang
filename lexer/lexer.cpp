#include<lexer.h>
#include<vector>


Lexer::Lexer(const std::string& text){
    this->input = text;
    this->pos = 0;
    this->line = 1;
}

void Lexer::skipWhitespace(){
    while(this->pos < this->input.size() && isspace(this->input[pos])){
        // isspace() returns true for ' ', '\n', '\t'
        // Character: ' ' -> isspace()? true
        // Character: '\t' -> isspace()? true
        // Character: '\n' -> isspace()? true
        // Character: '\v' -> isspace()? true
        // Character: '\f' -> isspace()? true
        // Character: '\r' -> isspace()? true
        // Character: A -> isspace()? false
        // Character: 1 -> isspace()? false
        // Character: # -> isspace()? false
        // Character: \0 -> isspace()? false

        // but with a peek() function we can make it more efficient and clean

        // but if there is \n it also means line++
        if(this->input[pos] == '\n') line++;
        pos++;
    }
}

std::vector<Token> Lexer::tokenize(){

    // list of all tokens
    std::vector<Token> tokens;
    // Token({type, value, line})

    // we check each character until we reach EOF
    // i.e until pos < input.size()

    while(this->pos < this->input.size()){
        // first of all skip all whitespaces
        this->skipWhitespace();
    }

    // when we reach EOF
    // add a token representing EOF to the list of tokens
    tokens.push_back({TokenType::EOF_TOKEN,"",this->line });

    // returns list of tokens
    return tokens;
}