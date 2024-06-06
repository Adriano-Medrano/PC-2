#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

const int MAX_ESTUDIANTES = 100;
const float NOTA_MINIMA_APROBADA = 10.5;

struct Estudiante {
    string codigo;
    string nombre;
    float nota1;
    float nota2;
    float nota3;
    float promedio;
};

void ingresarDatos(Estudiante estudiantes[], int &numEstudiantes) {
    if (numEstudiantes >= MAX_ESTUDIANTES) {
        cout << "No se pueden registrar más estudiantes.\n";
        return;
    }
    
    Estudiante nuevoEstudiante;
    cout << "Ingrese el codigo del estudiante: ";
    cin >> nuevoEstudiante.codigo;
    cin.ignore(); // Limpiar el buffer
    cout << "Ingrese el nombre del estudiante: ";
    getline(cin, nuevoEstudiante.nombre);
    cout << "Ingrese la nota 1: ";
    cin >> nuevoEstudiante.nota1;
    cout << "Ingrese la nota 2: ";
    cin >> nuevoEstudiante.nota2;
    cout << "Ingrese la nota 3: ";
    cin >> nuevoEstudiante.nota3;
    
    nuevoEstudiante.promedio = (nuevoEstudiante.nota1 + nuevoEstudiante.nota2 + nuevoEstudiante.nota3) / 3;
    
    estudiantes[numEstudiantes] = nuevoEstudiante;
    numEstudiantes++;
}

void mostrarPromedios(Estudiante estudiantes[], int numEstudiantes) {
    if (numEstudiantes == 0) {
        cout << "No hay estudiantes registrados.\n";
        return;
    }
    
    for (int i = 0; i < numEstudiantes; i++) {
        cout << "Estudiante: " << estudiantes[i].nombre << " - Promedio: " << estudiantes[i].promedio << endl;
    }
}

void contarDesaprobados(Estudiante estudiantes[], int numEstudiantes) {
    int desaprobados = 0;
    
    for (int i = 0; i < numEstudiantes; i++) {
        if (estudiantes[i].promedio < NOTA_MINIMA_APROBADA) {
            desaprobados++;
        }
    }
    
    cout << "Cantidad de estudiantes desaprobados: " << desaprobados << endl;
}

bool compararPromedio(const Estudiante &a, const Estudiante &b) {
    return a.promedio > b.promedio; // Orden descendente
}

void ordenarPorPromedios(Estudiante estudiantes[], int numEstudiantes) {
    sort(estudiantes, estudiantes + numEstudiantes, compararPromedio);
}

void mostrarDatosOrdenados(Estudiante estudiantes[], int numEstudiantes) {
    if (numEstudiantes == 0) {
        cout << "No hay estudiantes registrados.\n";
        return;
    }
    
    cout << left << setw(10) << "Codigo" << setw(20) << "Nombre" << setw(8) << "Nota 1" << setw(8) << "Nota 2" << setw(8) << "Nota 3" << "Promedio\n";
    for (int i = 0; i < numEstudiantes; i++) {
        cout << left << setw(10) << estudiantes[i].codigo << setw(20) << estudiantes[i].nombre << setw(8) << estudiantes[i].nota1 << setw(8) << estudiantes[i].nota2 << setw(8) << estudiantes[i].nota3 << estudiantes[i].promedio << endl;
    }
}

int main() {
    Estudiante estudiantes[MAX_ESTUDIANTES];
    int numEstudiantes = 0;
    int opcion;
    
    do {
        cout << "\nMenu de Opciones:\n";
        cout << "1. Ingresar datos de estudiante\n";
        cout << "2. Mostrar promedio de cada estudiante\n";
        cout << "3. Mostrar cantidad de estudiantes desaprobados\n";
        cout << "4. Ordenar y mostrar datos por promedio\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                ingresarDatos(estudiantes, numEstudiantes);
                break;
            case 2:
                mostrarPromedios(estudiantes, numEstudiantes);
                break;
            case 3:
                contarDesaprobados(estudiantes, numEstudiantes);
                break;
            case 4:
                ordenarPorPromedios(estudiantes, numEstudiantes);
                mostrarDatosOrdenados(estudiantes, numEstudiantes);
                break;
            case 5:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción no válida. Intente nuevamente.\n";
        }
    } while(opcion != 5);
    
    return 0;
}
