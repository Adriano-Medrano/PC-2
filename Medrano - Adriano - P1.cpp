//Enlace git: https://github.com/Adriano-Medrano/PC-2.git//
#include <iostream>
#include <string>

using namespace std;

const int numEnfermedades = 10;
const int numSintomas = 10;

int main() {
    // Lista de enfermedades
    string enfermedades[numEnfermedades] = {
        "gripe", "indigestión", "catarro", "migraña", "amigdalitis",
        "neumonía", "bronquitis", "sinusitis", "resfriado", "laringitis"
    };
    
    // Lista de síntomas
    string sintomas[numSintomas] = {
        "fiebre", "tos", "dolor de cabeza", "náuseas", "dolor de garganta",
        "congestión", "fatiga", "escalofríos", "dolor muscular", "pérdida de apetito"
    };
    
    // Matriz de sintomatologías
    bool sintomatologias[numEnfermedades][numSintomas] = {
        {1, 1, 1, 0, 0, 1, 1, 1, 1, 0},  // gripe
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 1},  // indigestión
        {0, 1, 1, 0, 1, 1, 0, 0, 0, 0},  // catarro
        {0, 0, 1, 1, 0, 0, 1, 0, 1, 0},  // migraña
        {1, 0, 0, 0, 1, 0, 1, 1, 0, 0},  // amigdalitis
        {1, 1, 0, 0, 1, 1, 1, 1, 1, 0},  // neumonía
        {0, 1, 0, 0, 1, 1, 1, 0, 0, 0},  // bronquitis
        {0, 1, 1, 0, 1, 1, 0, 0, 0, 0},  // sinusitis
        {0, 1, 1, 0, 0, 1, 0, 0, 0, 0},  // resfriado
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0}   // laringitis
    };

    // Respuestas del usuario
    bool respuestas[numSintomas];
    
    // Preguntar al usuario sobre cada síntoma
    cout << "Por favor, responda a las siguientes preguntas con '1' para Sí y '0' para No:\n";
    for (int i = 0; i < numSintomas; i++) {
        cout << "¿Tiene " << sintomas[i] << "? ";
        cin >> respuestas[i];
    }
    
    // Buscar la enfermedad que coincide con los síntomas del usuario
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
            cout << "Usted podría tener " << enfermedades[i] << ".\n";
            enfermedadEncontrada = true;
            break;
        }
    }
    
    if (!enfermedadEncontrada) {
        cout << "No se puede emitir un diagnóstico fiable con los síntomas proporcionados.\n";
    }

    return 0;
}
