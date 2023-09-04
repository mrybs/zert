//
// Created by mrybs on 03.09.23.
//

#pragma once


#include "ast.h"
#include "token.h"
#include "exceptions.h"

class Parser{
public:
    AST operator() (const std::string& filename, std::vector<Token> tokens){
        AST tree;
        tree.root = AST::Object{.name = filename};

        std::vector<AST::Object*> objects_traceback{&tree.root};
        int sdx = 0;

        int i = 0;
        while(i < tokens.size()){
            if(tokens[i].type == TokenType::EXECUTE){
                if(tokens[i+1].type != TokenType::SEMI) throw ParserException("Excepted ';'");
                tree.execute = tokens[i].value;
                i++;
            }
            else if(tokens[i].type == TokenType::INCLUDE){
                if(tokens[i+1].type != TokenType::SEMI) throw ParserException("Excepted ';'");
                tree.includes.push_back(tokens[i].value);
                i++;
            }
            else if(tokens[i].type == TokenType::CLASS_DEF){
                AST::Object new_class = {.name = tokens[i].value};
                int idx = i-1;
                while(tokens[idx].type == TokenType::FLAG){
                    new_class.flags.push_back(AST::Object::s2of(tokens[idx].value));
                    idx--;
                }
                objects_traceback[sdx]->classes.push_back(new_class);
                while(sdx+1 < objects_traceback.size())
                    objects_traceback.pop_back();
                objects_traceback.push_back(&objects_traceback[sdx]->classes[objects_traceback[sdx]->classes.size()-1]);
            }
            else if(tokens[i].type == TokenType::FUN_DEF){
                AST::Object new_fun = {.name = tokens[i].value};
                int idx = i-1;
                while(tokens[idx].type == TokenType::FLAG){
                    new_fun.flags.push_back(AST::Object::s2of(tokens[idx].value));
                    idx--;
                }
                objects_traceback[sdx]->functions.push_back(new_fun);
                while(sdx+1 < objects_traceback.size())
                    objects_traceback.pop_back();
                objects_traceback.push_back(&objects_traceback[sdx]->functions[objects_traceback[sdx]->functions.size()-1]);
            }
            else if(tokens[i].type == TokenType::OPEN_CURLY) sdx++;
            else if(tokens[i].type == TokenType::CLOSE_CURLY) sdx--;
            else if(tokens[i].type == TokenType::FUN){
                AST::Object::Call new_call{.what = tokens[i].value};

                while(tokens[i].type != TokenType::OPEN_BRACKET){
                    i++;
                }
                i++;
                while(tokens[i].type != TokenType::CLOSE_BRACKET){
                    new_call.args.push_back({
                            .type = AST::Object::Call::Arg::tt2at(tokens[i].type),
                            .value = tokens[i].value
                    });
                    i++;
                }
                if(tokens[i+1].type != TokenType::SEMI) throw ParserException("Excepted ';'");
                objects_traceback[sdx]->scope.push_back(new_call);
                i++;
            }else if(tokens[i].type == TokenType::VAR_DEF_TYPE){
                AST::Object::Call new_call{
                        .what = tokens[i].value,
                        .ret = tokens[i+1].value
                };
                new_call.args.push_back({AST::Object::Call::Arg::tt2at(tokens[i+2].type), tokens[i+2].value});
                objects_traceback[sdx]->scope.push_back(new_call);
                i += 2;
            }
            i++;
        }

        return tree;
    }
};