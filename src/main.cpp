/*
 * Metodología de la Programación: Language0
 * Curso 2022/2023
 */

/* 
 * File:   main.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 *
 * Created on 2 de febrero de 2023, 12:23
 */


/**
 * This program reads a text (without spaces) with a undefined number of 
 * characters and a text with two characters (bigram). It finds the bigrams 
 * contained in the first text, storing them in an array of Bigram. 
 * After that, the bigrams of the array are shown in the standard output. 
 * Then it converts to uppercase the bigrams in the array that are equals to the 
 * bigram of the second text. Finally the bigrams of the array are shown again 
 * in the standard output. 
 * Running example:
 * > language0 < data/SimpleText.txt
 */
using namespace std;
// Includes de c++
#include <iostream>
#include <string>

//Includes de nuestras clases

#include "Bigram.h";

int main(int argc, char* argv[]) {
    // This string contains the list of characters that are considered as
    // valid within a word. The rest of characters are considered as
    // separators
    const std::string validCharacters = "s";
    cout << validCharacters << endl;
    char a = 'b';
    char b = 'c';
    bool resultado = isValidCharacter(a , validCharacters);
    
    cout << resultado;
    // Read a text
    // Read a bigram (tex with two characters)
    
    // Find the bigrams in text and put them in an array of Bigrams
    
    // Show the bigrams stored in the array
    
    // Convert to uppercase the bigrams in the array that are equals to input bigram
    
    // Show again the bigrams stored in the array
}

