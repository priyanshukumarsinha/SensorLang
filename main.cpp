#include<bits/stdc++.h>
#include<lexer/lexer.h>
int main(int argc, char*argv[]){
    // in our program
    // A newline (\n) implicitly separates commands.
    // so doesn't need to end with ;

    if(argc!=2){
        std::cerr << "Usage: " << argv[0] << " <filename>\n";
        return 1;
    }

    std::string filename = argv[1];
    std::ifstream file(filename);
    if(!file){
        std::cerr << "ERROR :: FILE NOT FOUND :: " << filename << std::endl;
        return 1;
    }
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

    delete(lexer);
    return 0;
}