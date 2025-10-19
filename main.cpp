#include<bits/stdc++.h>
#include<lexer/lexer.h>
int main(){
    // in our program
    // A newline (\n) implicitly separates commands.
    // so doesn't need to end with ;
    std::ifstream file("examples/example.slang");
    std::stringstream buffer;
    buffer << file.rdbuf(); // read entire file
    std::string input = buffer.str();

    // lets bring our lexer here
    Lexer * lexer = new Lexer(input);
    std::vector<Token> tokens = lexer->tokenize();

    // print all tokens
    for (const auto& t : tokens) {
        std::cout << static_cast<int>(t.type) << " " << t.value << " [Line " << t.line << "]\n";
    }
    return 0;
}