//
// Created by mrybs on 11.12.22.
//

#pragma once


#include "token.h"
#include "exceptions.h"
#include <iostream>
#include <string>
#include <vector>

class Lexer{
public:
    int debug = 4;
    std::vector<Token> operator() (const std::string& code){
        std::vector<Token> tokens;
        std::vector<std::string> scd = code_split(code);
        unsigned long i = 0;

        while(i < scd.size()) {
            std::cout << i << " << " << scd[i] << "\n";
            if(scd[i] == "@"){
                if(scd[i+1] == "execute"){
                    if(scd[i+2] != "("){
                        throw LexerException("excepted '('");
                    }
                    if(not isStringLiteral(scd[i+3], scd[i+5])){
                        throw LexerException("excepted STRING_LITERAL ");
                    }
                    if(scd[i+6] != ")"){
                        throw LexerException("excepted ')'");
                    }
                    tokens.push_back({.type=TokenType::EXECUTE, .value=scd[i+4]});
                    i+=6;
                }else if(scd[i+1] == "include") {
                    if (scd[i + 2] != "(") {
                        throw LexerException("excepted '('");
                    }
                    if (not isStringLiteral(scd[i + 3], scd[i + 5])) {
                        throw LexerException("excepted STRING_LITERAL");
                    }
                    if (scd[i + 6] != ")") {
                        throw LexerException("excepted ')'");
                    }
                    tokens.push_back({.type = TokenType::INCLUDE, .value = scd[i + 4]});
                    i += 6;
                }
            }
            else if(scd[i] == "class"){
                int idx = i-1;
                while(scd[idx] != "}" and scd[idx] != ";" and scd[idx] != "{"){
                    tokens.push_back({.type = TokenType::FLAG, .value = scd[idx]});
                    idx--;
                }
                tokens.push_back({.type = TokenType::CLASS_DEF, .value = scd[i+1]});
                i++;
            }
            else if(scd[i] == "{") tokens.push_back({.type = TokenType::OPEN_CURLY});
            else if(scd[i] == "}") tokens.push_back({.type = TokenType::CLOSE_CURLY});
            else if(scd[i] == "(") tokens.push_back({.type = TokenType::OPEN_BRACKET});
            else if(scd[i] == ")") tokens.push_back({.type = TokenType::CLOSE_BRACKET});
            else if(scd[i] == ";") tokens.push_back({.type = TokenType::SEMI});
            else if(scd[i] == "fun"){
                int idx = i-1;
                while(scd[idx] != "}" and scd[idx] != ";" and scd[idx] != "{"){
                    tokens.push_back({.type = TokenType::FLAG, .value = scd[idx]});
                    idx--;
                }
                tokens.push_back({.type = TokenType::FUN_DEF, .value=scd[i+1]});
                tokens.push_back({.type = TokenType::OPEN_BRACKET});
                i += 3;
                std::vector<std::string> args = until(slice(scd, i), "(", ")");
                for(int idx = 0; idx < args.size(); idx++){
                    if(idx%3 == 0) tokens.push_back({.type = TokenType::ARG_TYPE, .value = scd[i]});
                    else if(idx%3 == 1) tokens.push_back({.type = TokenType::ARG_NAME, .value = scd[i]});
                    else if(scd[i] != ",") throw LexerException("excepted ','");
                    i++;
                }
                tokens.push_back({.type = TokenType::CLOSE_BRACKET});
            }
            else{
                if(scd[i+1] == "("){
                    tokens.push_back({.type = TokenType::FUN, .value = scd[i]});
                    tokens.push_back({.type = TokenType::OPEN_BRACKET});
                    i += 2;
                    std::vector<std::string> raw_args = until(slice(scd, i), "(", ")");
                    std::vector<std::vector<std::string>> args{{}};
                    for(const std::string& raw_arg : raw_args){
                        if(raw_arg == ",")
                            args.push_back({});
                        else {
                            args[args.size() - 1].push_back(raw_arg);
                        }
                    }
                    for(int idx = 0; idx < args.size(); idx++){
                        if(args[idx][0] == "'" or args[idx][0] == "\""){
                            if (args[idx][2] != args[idx][0]) throw LexerException("excepted '" + args[idx][0] + "'");
                            tokens.push_back({.type = TokenType::STRING_LITERAL, .value = args[idx][1]});
                        }else{
                            try{
                                tokens.push_back({.type = TokenType::NUMERIC_LITERAL, .value = std::to_string(std::stod(args[idx][0]))});
                            }catch(std::invalid_argument){
                                tokens.push_back({.type = TokenType::VAR, .value = args[idx][0]});
                            }
                        }
                        i += args[idx].size();
                    }
                    i += args.size()-1;
                    tokens.push_back({.type = TokenType::CLOSE_BRACKET});
                }
                else if(scd[i+2] == "="){
                    tokens.push_back({.type = TokenType::VAR_DEF_TYPE, .value = scd[i]});
                    tokens.push_back({.type = TokenType::VAR_DEF_NAME, .value = scd[i+1]});

                    std::vector<std::string> var_init = until(slice(scd, i+3), "", ";");
                    if(var_init.size() == 1){
                        try{
                            tokens.push_back({.type = TokenType::NUMERIC_LITERAL, .value = std::to_string(std::stod(var_init[0]))});
                        }catch(std::invalid_argument){
                            tokens.push_back({.type = TokenType::VAR, .value = var_init[0]});
                        }
                    }else if(var_init.size() == 3){
                        if(var_init[0] == "'" or var_init[0] == "\""){
                            if (var_init[2] != var_init[0]) throw LexerException("excepted '" + var_init[0] + "'");
                            tokens.push_back({.type = TokenType::STRING_LITERAL, .value = var_init[1]});
                        }
                    }
                    i += var_init.size() + 1;
                }
                else if(scd[i+1] == "="){
                    tokens.push_back({.type = TokenType::VAR_SET_NAME, .value = scd[i]});

                    std::vector<std::string> var_init = until(slice(scd, i+2), "", ";");
                    if(var_init.size() == 1){
                        try{
                            tokens.push_back({.type = TokenType::NUMERIC_LITERAL, .value = std::to_string(std::stod(var_init[0]))});
                        }catch(std::invalid_argument){
                            tokens.push_back({.type = TokenType::VAR, .value = var_init[0]});
                        }
                    }else if(var_init.size() == 3){
                        if(var_init[0] == "'" or var_init[0] == "\""){
                            if (var_init[2] != var_init[0]) throw LexerException("excepted '" + var_init[0] + "'");
                            tokens.push_back({.type = TokenType::STRING_LITERAL, .value = var_init[1]});
                        }
                    }
                    i += var_init.size();
                }
            }
            i++;
        }
        return tokens;
    }
private:
    std::vector<std::string> nonempty(const std::vector<std::string>& words){
        std::vector<std::string> _words;
        for(std::string word : words)
            if(word != "" and word != "\n" and word != "\t" and word != " ")
                _words.push_back(word);
        return _words;
    }

    std::vector<std::string> code_split(const std::string& code){
        std::vector<std::string> words;
        std::string buf;
        char quote;

        for(char c : code){
            if(quote == c) {
                quote = 0;
            }
            else if(quote == 0 and (c == '\'' or c == '"')) {
                quote = c;
            }
            if(quote == 0 or quote == c){
                if(not std::isalnum(c) and c != '.'){
                    words.push_back(buf);
                    words.push_back(std::string(1, c));
                    buf = "";
                    continue;
                }
            }
            buf += c;
        }

        words.push_back(buf);
        return nonempty(words);
    }

    bool isStringLiteral(const std::string& q1, const std::string& q2){
        return q1 == q2 and (q1 == "\'" or q1 == "\"");
    }

    std::vector<std::string> slice(const std::vector<std::string>& words, int from){
        std::vector<std::string> _words;
        for(int i = from; i < words.size(); i++){
            _words.push_back(words[i]);
        }
        return _words;
    }

    std::vector<std::string> until(const std::vector<std::string>& words, const std::string& from_word, const std::string& until_word){
        std::vector<std::string> _words;
        int dx = 0;
        for(const std::string& word : words){
            if(dx == 0 and word == until_word)
                break;
            if(word == from_word) dx++;
            if(word == until_word) dx--;
            _words.push_back(word);
        }
        return _words;
    }
};