//
// Created by mrybs on 03.09.23.
//

#pragma once


#include <string>
#include <sstream>
#include <vector>
#include "token.h"

std::string get_offset(int offset){
    std::string res;
    for(int i = 0; i < offset; i++)
        res += "  ";
    return res;
}

struct AST{
    struct Object{
        struct Call{
            struct Arg{
                enum class ArgType{
                    STRING_LITERAL,
                    NUMERIC_LITERAL,
                    VAR
                };
                ArgType type;
                std::string value;
                std::string display(int offset=0){
                    std::stringstream ss;
                    ss << get_offset(offset) << "Type: " << at2s(type) << std::endl;
                    ss << get_offset(offset) << "Value: " << value << std::endl;
                    return ss.str();
                }
                std::string at2s(ArgType arg_type){
                    switch (arg_type) {
                        case ArgType::STRING_LITERAL:
                            return "STRING_LITERAL";
                        case ArgType::NUMERIC_LITERAL:
                            return "NUMERIC_LITERAL";
                        case ArgType::VAR:
                            return "VAR";
                    }
                    return "UNDEFINED";
                }
                static ArgType tt2at(const TokenType &token_type){
                    switch(token_type){
                        case TokenType::STRING_LITERAL:
                            return ArgType::STRING_LITERAL;
                        case TokenType::NUMERIC_LITERAL:
                            return ArgType::NUMERIC_LITERAL;
                        case TokenType::VAR:
                            return ArgType::VAR;
                    }
                    return ArgType::VAR;
                }
            };
            std::string what;
            std::vector<Arg> args;
            std::string ret;

            std::string display(int offset=0){
                std::stringstream ss;
                ss << get_offset(offset) << "What: " << what << std::endl;
                for(int i = 0; i < args.size(); i++){
                    ss << get_offset(offset) << "Arg " << i+1 << ": " << std::endl;
                    ss << args[i].display(offset+1);
                }
                ss << get_offset(offset) << "Return: " << ret << std::endl;
                return ss.str();
            }
        };
        enum class ObjectFlag{
            ASM,
            GLOBAL,
            STATIC,
            EXTEND,
            UNDEFINED
        };
        std::string name;
        std::vector<ObjectFlag> flags;
        std::vector<Object> global_classes;
        std::vector<Object> global_functions;
        std::vector<Object> classes;
        std::vector<Object> functions;
        std::vector<Call> scope;

        std::string display(int offset=0){
            std::stringstream ss;
            ss << get_offset(offset) << "Name: " << name << std::endl;
            for(int i = 0; i < flags.size(); i++){
                ss << get_offset(offset) << "Flag " << i+1 << ": " << of2s(flags[i]) << std::endl;
            }
            for(int i = 0; i < global_classes.size(); i++){
                ss << get_offset(offset) << "Global Class " << i+1 << ": " << std::endl;
                ss << global_classes[i].display(offset+1);
            }
            for(int i = 0; i < global_functions.size(); i++){
                ss << get_offset(offset) << "Global Function " << i+1 << ": " << std::endl;
                ss << global_functions[i].display(offset+1);
            }
            for(int i = 0; i < classes.size(); i++){
                ss << get_offset(offset) << "Class " << i+1 << ": " << std::endl;
                ss << classes[i].display(offset+1);
            }
            for(int i = 0; i < functions.size(); i++){
                ss << get_offset(offset) << "Function " << i+1 << ": " << std::endl;
                ss << functions[i].display(offset+1);
            }
            for(int i = 0; i < scope.size(); i++){
                ss << get_offset(offset) << "Call " << i+1 << ": " << std::endl;
                ss << scope[i].display(offset+1);
            }
            return ss.str();
        }
        static std::string of2s(ObjectFlag object_flag){
            switch (object_flag) {
                case ObjectFlag::ASM:
                    return "ASM";
                case ObjectFlag::GLOBAL:
                    return "GLOBAL";
                case ObjectFlag::STATIC:
                    return "STATIC";
                case ObjectFlag::EXTEND:
                    return "EXTEND";
                case ObjectFlag::UNDEFINED:
                    return "UNDEFINED";
            }
            return "UNDEFINED";
        }
        static ObjectFlag s2of(std::string token_value){
            if(token_value == "asm")
                return ObjectFlag::ASM;
            if(token_value == "global")
                return ObjectFlag::GLOBAL;
            if(token_value == "static")
                return ObjectFlag::STATIC;
            if(token_value == "extend")
                return ObjectFlag::EXTEND;
            return ObjectFlag::UNDEFINED;
        }
    };
    std::string execute;
    std::vector<std::string> includes;
    Object root;

    std::string display(int offset=0){
        std::stringstream ss;
        ss << get_offset(offset) << "Execute: " << execute << std::endl;
        for(int i = 0; i < includes.size(); i++){
            ss << get_offset(offset) << "Include " << i+1 << ": " << includes[i] << std::endl;
        }
        ss << get_offset(offset) << "Root: " << std::endl;
        ss << root.display(offset+1);
        return ss.str();
    }
};
