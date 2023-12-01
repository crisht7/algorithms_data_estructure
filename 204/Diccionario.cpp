#include "Diccionario.h"
#include <sstream>
#include <iostream>

/**
 * @brief Constructor de la clase Diccionario.
 */
Diccionario::Diccionario(){

}

/**
 * @brief Inserta una palabra en el diccionario.
 * 
 * Esta función inserta la palabra proporcionada en la tabla de dispersión, normalizando
 * la palabra antes de realizar la inserción. Utiliza el método "insertar()" de
 * la clase de tabla de dispersión asociada al diccionario.
 * 
 * @param palabra Palabra a insertar en el diccionario.
 * @return None
 */
void Diccionario::insertarPalabra(string palabra){
    tablaDispersion.insertar(normalizarPalabra(palabra));
}

/**
 * @brief Consulta si una palabra está presente en el diccionario.
 * 
 * Esta función consulta si la palabra proporcionada está presente en el diccionario,
 * normalizando la palabra antes de realizar la consulta. Utiliza el método "existeClave()"
 * de la clase de tabla de dispersión asociada al diccionario.
 * 
 * @param palabra Palabra a consultar en el diccionario.
 * @return True si la palabra está presente, False si no.
 */
bool Diccionario::consultarPalabra(string palabra){
    return tablaDispersion.existePalabra(normalizarPalabra(palabra));
}

/**
 * @brief Vacía el contenido del diccionario.
 * 
 * Esta función vacía el contenido del diccionario utilizando el método "vaciar()"
 * de la clase de tabla de dispersión asociada al diccionario.
 * 
 * @return None
 */
void Diccionario::vaciar(){
    tablaDispersion.vaciar();
}

/**
 * @brief Obtiene el tamaño actual del diccionario.
 * 
 * Esta función devuelve el tamaño actual del diccionario, que corresponde al
 * número de elementos almacenados en la tabla de dispersión asociada.
 * 
 * @return Tamaño actual del diccionario.
 */
int Diccionario::getTamanio(){
    return tablaDispersion.getTamanio();
}

string Diccionario::getJuanagrama(string palabra){
    return tablaDispersion.encontrarJuanagrama(normalizarPalabra(palabra));
}

/**
 * @brief Normaliza una palabra de texto según las reglas.
 * 
 * Esta función toma una cadena de texto como entrada y aplica las reglas de normalización
 * para transformar caracteres especiales, como letras con acentos, en su forma no acentuada o
 * en mayúsculas. Utiliza un bucle para recorrer la cadena de entrada y aplica las transformaciones
 * necesarias. Devuelve la cadena normalizada como resultado.
 * 
 * @param texto Cadena de texto a normalizar.
 * @return Cadena normalizada según las reglas definidas.
 */
string Diccionario::normalizarPalabra(string texto) {
    string resultado;
    size_t i = 0;
    
    while (i < texto.length()) {
        char byte1 = texto[i];
        
        if (byte1 == '\xC3') {
            char byte2 = texto[i + 1];
            switch (byte2) {
                case '\xA1':
                    resultado.push_back(static_cast<char>(0x41));
                    break;  // á*
                case '\xA9':
                    resultado.push_back(static_cast<char>(0x45));
                    break; //é
                case '\xAD':
                    resultado.push_back(static_cast<char>(0x49));
                    break;  // í*
                case '\xB3':
                    resultado.push_back(static_cast<char>(0x4F));
                    break;  // ó*
                case '\xBA':
                    resultado.push_back(static_cast<char>(0x55));
                    break;  // ú*
                case '\xBC':
                    resultado.push_back(static_cast<char>(0xC3));
                    resultado.push_back(static_cast<char>(0x9C));
                    break;  // ü*  
                case '\xB1':
                    resultado.push_back(static_cast<char>(0xC3));
                    resultado.push_back(static_cast<char>(0x91));
                    break;  // ñ*
                case '\x81':
                    resultado.push_back(static_cast<char>(0x41));
                    break;  // Á*
                case '\x89':
                    resultado.push_back(static_cast<char>(0x45));
                    break;  // É*
                case '\x8D':
                    resultado.push_back(static_cast<char>(0x49));
                    break;  // Í*
                case '\x93':
                    resultado.push_back(static_cast<char>(0x4F));
                    break;  // Ó*
                case '\x9A':
                    resultado.push_back(static_cast<char>(0x55));
                    break;  // Ú*
                case '\x9C':
                    resultado.push_back(static_cast<char>(0xC3));
                    resultado.push_back(static_cast<char>(0x9C));
                    break;  // Ü*
                case '\x91':
                    resultado.push_back(static_cast<char>(0xC3));
                    resultado.push_back(static_cast<char>(0x91));
                    break;  // Ñ
                default:
                    resultado.push_back(static_cast<char>(0xC3));
                    resultado.push_back(static_cast<char>(byte2));
                // si no es cualquiera de esos, que se añada, solo hay que tratar esos, aquí vendrian los caracteres tipo ç à
            }
            i += 2; // Saltar al siguiente porque este caracter son 2 bytes
        } else {
            resultado.push_back(static_cast<char>(toupper(byte1)));
            i++;
        }
    }
    
    return resultado;
}