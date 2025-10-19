#include<bits/stdc++.h>
#include<lexer.h>
int main(){
    // in our program
    // A newline (\n) implicitly separates commands.
    // so doesn't need to end with ;
    std::string input = R"(
# Temperature monitoring
read tempSensor
write output, 100
alert 2025-10-09T13:00:00
)";

    // lets bring our lexer here
    Lexer * lexer = new Lexer(input);
    std::vector<Token> tokens = lexer->tokenize();

    // print all tokens
    for (const auto& t : tokens) {
        std::cout << static_cast<int>(t.type) << " " << t.value << " [Line " << t.line << "]\n";
    }
    return 0;
}