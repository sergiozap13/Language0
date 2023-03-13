/*
 * Metodología de la Programación: Language0
 * Curso 2022/2023
 */

/* 
 * File:   main.cpp
 * @author Sergio Zapata De la Hoz <sergiozap@correo.ugr.es>
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

int main(int argc, char* argv[]) {
    // This string contains the list of characters that are considered as
    // valid within a word. The rest of characters are considered as
    // separators
    
    const std::string validCharacters = "abcdefghijklmnopqrstuTvwxyz\xE0\xE1\xE2\xE3\xE4\xE5\xE6\xE7\xE8\xE9\xEA\xEB\xEC\xED\xEE\xEF\xF0\xF1\xF2\xF3\xF4\xF5\xF6\xF8\xF9\xFA\xFB\xFC\xFD\xFE\xFF";
    //cout << validCharacters << endl << endl;
    
    // Read a text
    
    // Leemos el texto del cual vamos a extraer los bigramas
    string cadena1 = "";
    cout << "Enter a text: " << endl;
    cin >> cadena1; 
    
    // Read a bigram (text with two characters)
    
    // Leemos el bigrama a buscar
    string cadena2 = "";
    
    // Validación de que la cadena a buscar va a tener 2 caracteres
    do{
        cout << "Enter the pair of characters to search: " << endl;
        cin >> cadena2;
    } while(cadena2.length() != 2);
    
    Bigram bigram1(cadena2);
   
    // Find the bigrams in text and put them in an array of Bigrams
    
    // Declaramos un array de Bigramas con el tamaño de la longitud del texto. 
    Bigram bigrams[cadena1.length()];
    
    int tam_bigrams = 0;
    int i = 0;
    
    // Recorremos el texto 
    while(i <= cadena1.length()){
        // Si los dos caracteres consecutivos están presentes en el validCharacters: 
        if(isValidCharacter(cadena1[i],validCharacters) && isValidCharacter(cadena1[i+1], validCharacters)){
            // Se añaden al vector de Bigramas
            bigrams[tam_bigrams].at(0) = cadena1[i];
            bigrams[tam_bigrams].at(1) = cadena1[i+1];
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
       
    // Convert to uppercase the bigrams in the array that are equals to cadena1 bigram
 
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

