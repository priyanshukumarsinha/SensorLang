#include"lexer.h"
#include<vector>
#include<bits/stdc++.h>


Lexer::Lexer(const std::string& text){
    this->input = text;
    this->pos = 0;
    this->line = 1;
}

std::string Lexer::readIdentifier(){
    size_t start = this->pos;
    // [a-zA-Z_][a-zA-Z0-9_]*
    // it should always start with an alphabet or _; isalpha() or _
    if(isalpha(this->peek()) || peek() == '_'){
        // then it must be an identifier
        // now after the first letter being an alphabet or a number or an underscore
        // next letter could be alnum or _
        // isalnum() || _
        while(isalnum(peek()) || peek() == '_'){
            // stops if we encounter any other symbol or space
            pos++;
        }

        // return substring from start position to current position
        return this->input.substr(start, pos-start);

    }

    // if does not start with an alphabet or _ then it must not be an identifier
    return "";
}

bool Lexer::isKeyword(std::string &id){
    if(id=="read" || id=="write" || id == "alert") return 1;
    return 0;
}

std::string Lexer::readInteger(){
    // it should start with an integer
    size_t start = this->pos;
    if(isdigit(peek())){
        this->pos++;
        while(isdigit(peek())){
            this->pos++;
        }
        return this->input.substr(start, this->pos-start);
    }
    return "";
}

char Lexer::peek(){
    return (this->pos < this->input.size())?input[pos]:'\0';
    // returns current element i.e input[pos]
    // without incrementing pos
}

void Lexer::skipWhitespace(){
    while(isspace(this->peek())){
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

        // but if there is \n it also means line++
        if(peek() == '\n') line++;
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
        
        // now lets check if the current element, i.e peek() is any type of token
        // 1. keyword : read | write | alert
        // but a keyword is almost similar to an identifier
        // actually an identifier is not a keyword, only if its value is not read or write or alert here
        // so first we need to check if it is an identifier
        // 2. Identifier [a-zA-Z_][a-zA-Z0-9_]*
        std::string id = this->readIdentifier();
        if(!id.empty()){
            // that means it is an identifier
            // now it could also be a keyword, we need to check for that
            if(this->isKeyword(id)){
                tokens.push_back({TokenType::KEYWORD, id, this->line});
            }
            else{
                tokens.push_back({TokenType::IDENTIFIER, id, this->line});
            }

            // if it is an identifier, then continue
            continue;
        }

        // 3. Integer_literal [0-9]+ (fist we need to check for timestamp)
        // if we check for integer first, timestamp's 2025-... 2025 will be treated as an integer
        std::string num = this->readInteger();
        if(!num.empty()){
            tokens.push_back({TokenType::INTEGER_LITERAL, num, this->line});
        }
        pos++;

    }

    // when we reach EOF
    // add a token representing EOF to the list of tokens
    tokens.push_back({TokenType::EOF_TOKEN,"",this->line });

    // returns list of tokens
    return tokens;
}