//
// Created by mrybs on 11.12.22.
//


#include "lexer.h"
#include "parser.h"
#include <fstream>


int main() {
    std::ifstream file("example.zert");
    std::string line;
    std::string code = "";

    if (file.is_open())
        while (getline(file, line))
            code += line + "\n";
    file.close();

    try{
        Lexer lexer{.debug=0};
        std::vector<Token> tokens = lexer(code);
        for(int i = 0; i < tokens.size(); i++)
            std::cout << std::string(tokens[i]) << std::endl;

        Parser parser;
        AST tree = parser("example.zert", tokens);
        std::cout << std::endl << std::endl << "Abstract Syntax Tree: \n" << tree.display();
    }catch(LexerException e){
        std::cout << e.what();
    }catch(ParserException e){
        std::cout << e.what();
    }
    return 0;
}