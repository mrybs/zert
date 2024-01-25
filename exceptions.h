//
// Created by mrybs on 03.09.23.
//

#pragma once


#include <exception>
#include <string>

class CompileException : std::exception{
protected:
    std::string reason;
public:
    inline CompileException(std::string reason){
        this->reason = reason;
    }
    const char* what(){
        return (new std::string("CompileException: " + reason))->c_str();
    }
};

class LexerException : CompileException{
public:
    inline LexerException(std::string reason) : CompileException(reason){}
    const char* what(){
        return (new std::string("LexerException: " + reason))->c_str();
    }
};

class ParserException : CompileException{
public:
    inline ParserException(std::string reason) : CompileException(reason){}
    const char* what(){
        return (new std::string("ParserException: " + reason))->c_str();
    }
};