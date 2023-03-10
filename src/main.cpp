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

#include "Bigram.h"

// Función para poner en minúscula un Bigrama
void toLower(Bigram &bigram){
    int tam = bigram.getText().length();
    
    for (int i = 0; i < tam; i++){
        if(isupper(bigram.at(i))){
            bigram.at(i) = std::tolower(bigram.at(i)); 
        }
    }
}

int main(int argc, char* argv[]) {
    // This string contains the list of characters that are considered as
    // valid within a word. The rest of characters are considered as
    // separators
    
    const std::string validCharacters = "abcdefghijklmnopqrstuTvwxyz\xE0\xE1\xE2\xE3\xE4\xE5\xE6\xE7\xE8\xE9\xEA\xEB\xEC\xED\xEE\xEF\xF0\xF1\xF2\xF3\xF4\xF5\xF6\xF8\xF9\xFA\xFB\xFC\xFD\xFE\xFF";
    cout << validCharacters << endl << endl;
    
    // Read a text
    
    // Leemos el texto del cual vamos a extraer los bigramas
    string input = "";
    cout << "Introduce a text: ";
    cin >> input; 
    
    // Read a bigram (text with two characters)
    
    // Leemos el bigrama a buscar
    char a, b;
    
    cout << "Introduce the first character: ";
    cin >> a; 
    cout << "Introduce the second character: ";
    cin >> b;
    
    cout << endl;
    
    Bigram bigram1(a,b);
    
    // Find the bigrams in text and put them in an array of Bigrams
    
    // Declaramos un array de Bigramas con el tamaño de la longitud del texto. 
    Bigram bigrams[input.length()];
    
    int tam_bigrams = 0;
    int i = 0;
    
    // Recorremos el texto 
    while(i <= input.length()){
        // Si los dos caracteres consecutivos están presentes en el validCharacters: 
        if(isValidCharacter(input[i],validCharacters) && isValidCharacter(input[i+1], validCharacters)){
            // Se añaden al vector de Bigramas
            bigrams[tam_bigrams].at(0) = input[i];
            bigrams[tam_bigrams].at(1) = input[i+1];
            tam_bigrams++;
        } else 
            i++; // En caso de no tener dos caracteres válidos consecutivos        
        // Pasamos al siguiente Bigrama.
        i++;
    }
    
    // Show the bigrams stored in the array
    
    // Recorremos el vector de Bigramas 
    cout << "11" << endl;
    for(int i = 0; i < tam_bigrams ; i++){
        // Lo pasamos a minúsculas para evitar distinguir mayusculas y minúsculas
        toLower(bigrams[i]);
        // Se muestra el bigrama
        cout << bigrams[i].getText() << endl;
    }
 
       cout << endl;
       
    // Convert to uppercase the bigrams in the array that are equals to input bigram
 
    // Recorremos todo el vector
    for(int i = 0; i < tam_bigrams; i++){
       if(bigrams[i].getText() == bigram1.getText()){
           toUpper(bigrams[i]);
       } 
    }
    // Show again the bigrams stored in the array
    cout << "11" << endl;
    for(int i = 0; i < tam_bigrams ; i++){
        cout <<  bigrams[i].getText() << endl;
    }
}

