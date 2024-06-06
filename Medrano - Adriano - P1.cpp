//Enlace git: https://github.com/Adriano-Medrano/PC-2.git//
#include <iostream>
#include <string>

using namespace std;

const int numEnfermedades = 10;
const int numSintomas = 10;

int main() {
    // Lista de enfermedades
    string enfermedades[numEnfermedades] = {
        "gripe", "indigesti�n", "catarro", "migra�a", "amigdalitis",
        "neumon�a", "bronquitis", "sinusitis", "resfriado", "laringitis"
    };
    
    // Lista de s�ntomas
    string sintomas[numSintomas] = {
        "fiebre", "tos", "dolor de cabeza", "n�useas", "dolor de garganta",
        "congesti�n", "fatiga", "escalofr�os", "dolor muscular", "p�rdida de apetito"
    };
    
    // Matriz de sintomatolog�as
    bool sintomatologias[numEnfermedades][numSintomas] = {
        {1, 1, 1, 0, 0, 1, 1, 1, 1, 0},  // gripe
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 1},  // indigesti�n
        {0, 1, 1, 0, 1, 1, 0, 0, 0, 0},  // catarro
        {0, 0, 1, 1, 0, 0, 1, 0, 1, 0},  // migra�a
        {1, 0, 0, 0, 1, 0, 1, 1, 0, 0},  // amigdalitis
        {1, 1, 0, 0, 1, 1, 1, 1, 1, 0},  // neumon�a
        {0, 1, 0, 0, 1, 1, 1, 0, 0, 0},  // bronquitis
        {0, 1, 1, 0, 1, 1, 0, 0, 0, 0},  // sinusitis
        {0, 1, 1, 0, 0, 1, 0, 0, 0, 0},  // resfriado
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0}   // laringitis
    };

    // Respuestas del usuario
    bool respuestas[numSintomas];
    
    // Preguntar al usuario sobre cada s�ntoma
    cout << "Por favor, responda a las siguientes preguntas con '1' para S� y '0' para No:\n";
    for (int i = 0; i < numSintomas; i++) {
        cout << "�Tiene " << sintomas[i] << "? ";
        cin >> respuestas[i];
    }
    
    // Buscar la enfermedad que coincide con los s�ntomas del usuario
    bool enfermedadEncontrada = false;
    for (int i = 0; i < numEnfermedades; i++) {
        bool coincide = true;
        for (int j = 0; j < numSintomas; j++) {
            if (sintomatologias[i][j] != respuestas[j]) {
                coincide = false;
                break;
            }
        }
        if (coincide) {
            cout << "Usted podr�a tener " << enfermedades[i] << ".\n";
            enfermedadEncontrada = true;
            break;
        }
    }
    
    if (!enfermedadEncontrada) {
        cout << "No se puede emitir un diagn�stico fiable con los s�ntomas proporcionados.\n";
    }

    return 0;
}
