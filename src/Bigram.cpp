/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bigram.cpp
 * Author: sergio
 * 
 * Created on 5 de marzo de 2023, 13:44
 */

#include <string>

#include "Bigram.h"

Bigram::Bigram(const std::string& text) {
    this->_text = text;
}

Bigram::Bigram(char first, char second) {
    std::string text;
    text= first + second;
    this->_text = text;
    // POR HACER
}

std::string Bigram::getText() const{
    return this->_text;
}

std::string Bigram::toString() const{
    //POR HACER
}

const char& Bigram::at(int index) const{
    return _text[index];
}

char& Bigram::at(int index){
    return _text[index];
}

bool isValidCharacter(char character, const std::string& validCharacters){
    int tam = validCharacters.length();
    
    for(int i = 0; i < tam; i++){
        if (character == validCharacters[i]){
            return true;
        }
    }
    return false;
}

void toUpper(Bigram &bigram){
    int tam = bigram.getText().length();
    
    for (int i = 0; i < tam; i++){
        if(islower(bigram.at(i))){
            bigram.at(i) = std::toupper(bigram.at(i)); 
        }
    }
}
