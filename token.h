//
// Created by mrybs on 11.12.22.
//

#pragma once


#include <string>


enum class TokenType{
    EXECUTE,
    INCLUDE,
    CLASS_DEF,
    FUN_DEF,
    FLAG,
    ARG_TYPE,
    ARG_NAME,
    OPEN_CURLY,
    CLOSE_CURLY,
    OPEN_BRACKET,
    CLOSE_BRACKET,
    STRING_LITERAL,
    NUMERIC_LITERAL,
    VAR,
    VAR_DEF_NAME,
    VAR_DEF_TYPE,
    VAR_SET_NAME,
    FUN,
    SEMI
};

struct Token{
    TokenType type;
    std::string value;

    operator std::string (){
        if(value.empty())
            return tt2s(type)+";";
        return tt2s(type)+", "+value+";";
    }
    static std::string tt2s(TokenType token_type){
        switch (token_type) {
            case TokenType::EXECUTE:
                return "EXECUTE";
            case TokenType::INCLUDE:
                return "INCLUDE";
            case TokenType::CLASS_DEF:
                return "CLASS_DEF";
            case TokenType::FUN_DEF:
                return "FUN_DEF";
            case TokenType::ARG_TYPE:
                return "ARG_TYPE";
            case TokenType::ARG_NAME:
                return "ARG_NAME";
            case TokenType::FLAG:
                return "FLAG";
            case TokenType::OPEN_CURLY:
                return "OPEN_CURLY";
            case TokenType::CLOSE_CURLY:
                return "CLOSE_CURLY";
            case TokenType::OPEN_BRACKET:
                return "OPEN_BRACKET";
            case TokenType::CLOSE_BRACKET:
                return "CLOSE_BRACKET";
            case TokenType::STRING_LITERAL:
                return "STRING_LITERAL";
            case TokenType::NUMERIC_LITERAL:
                return "NUMERIC_LITERAL";
            case TokenType::VAR:
                return "VAR";
            case TokenType::VAR_DEF_NAME:
                return "VAR_DEF_NAME";
            case TokenType::VAR_DEF_TYPE:
                return "VAR_DEF_TYPE";
            case TokenType::VAR_SET_NAME:
                return "VAR_SET_NAME";
            case TokenType::FUN:
                return "FUN";
            case TokenType::SEMI:
                return "SEMI";
        }
        return "UNDEFINED";
    }
};