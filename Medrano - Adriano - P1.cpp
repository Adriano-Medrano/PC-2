#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_ALUMNOS = 100;
const int NUM_CURSOS = 3;

struct Alumno {
    string codigo;
    string nombre;
    string genero;
    int edad;
    float notas[NUM_CURSOS];
    float promedio;
};

void registrarAlumno(Alumno alumnos[], int &numAlumnos) {
    if (numAlumnos >= MAX_ALUMNOS) {
        cout << "No se pueden registrar mas alumnos.\n";
        return;
    }
    Alumno nuevoAlumno;
    
    cout << "Ingrese el codigo del alumno: ";
    cin >> nuevoAlumno.codigo;
    cin.ignore(); // Limpiar el buffer
    cout << "Ingrese el nombre del alumno: ";
    getline(cin, nuevoAlumno.nombre);
    cout << "Ingrese el genero del alumno: ";
    cin >> nuevoAlumno.genero;
    cout << "Ingrese la edad del alumno: ";
    cin >> nuevoAlumno.edad;
    
    for (int i = 0; i < NUM_CURSOS; i++) {
        cout << "Ingrese la nota del curso " << i + 1 << ": ";
        cin >> nuevoAlumno.notas[i];
    }
    
    nuevoAlumno.promedio = 0;
    for (int i = 0; i < NUM_CURSOS; i++) {
        nuevoAlumno.promedio += nuevoAlumno.notas[i];
    }
    nuevoAlumno.promedio /= NUM_CURSOS;
    
    alumnos[numAlumnos] = nuevoAlumno;
    numAlumnos++;
}

void verListaAlumnos(Alumno alumnos[], int numAlumnos) {
    if (numAlumnos == 0) {
        cout << "No hay alumnos registrados.\n";
        return;
    }
    cout << left << setw(10) << "Codigo" << setw(20) << "Nombre" << setw(10) << "Genero" << setw(5) << "Edad" << "Promedio\n";
    for (int i = 0; i < numAlumnos; i++) {
        cout << left << setw(10) << alumnos[i].codigo << setw(20) << alumnos[i].nombre << setw(10) << alumnos[i].genero << setw(5) << alumnos[i].edad << alumnos[i].promedio << endl;
    }
}

void verNotasPorAsignatura(Alumno alumnos[], int numAlumnos) {
    if (numAlumnos == 0) {
        cout << "No hay alumnos registrados.\n";
        return;
    }
    cout << left << setw(10) << "Codigo" << setw(20) << "Nombre";
    for (int i = 0; i < NUM_CURSOS; i++) {
        cout <<setw(10)<<"Curso"<<i+1<<" ";
    }
    cout << endl;
    
    for (int i = 0; i < numAlumnos; i++) {
        cout << left << setw(10) << alumnos[i].codigo << setw(20) << alumnos[i].nombre;
        for (int j = 0; j < NUM_CURSOS; j++) {
            cout << setw(10) << alumnos[i].notas[j];
        }
        cout << endl;
    }
}

void calcularPromedio(Alumno alumnos[], int numAlumnos) {
    if (numAlumnos == 0) {
        cout << "No hay alumnos registrados.\n";
        return;
    }
    for (int i = 0; i < numAlumnos; i++) {
        float promedio = 0;
        for (int j = 0; j < NUM_CURSOS; j++) {
            promedio += alumnos[i].notas[j];
        }
        promedio /= NUM_CURSOS;
        alumnos[i].promedio = promedio;
    }
    cout << "Promedios calculados.\n";
}

void mostrarPrimeroYUltimo(Alumno alumnos[], int numAlumnos) {
    if (numAlumnos == 0) {
        cout << "No hay alumnos registrados.\n";
        return;
    }
    cout << "Primer alumno registrado:\n";
    cout << left << setw(10) << "Codigo" << setw(20) << "Nombre" << setw(10) << "Genero" << setw(5) << "Edad" << "Promedio\n";
    cout << left << setw(10) << alumnos[0].codigo << setw(20) << alumnos[0].nombre << setw(10) << alumnos[0].genero << setw(5) << alumnos[0].edad << alumnos[0].promedio << endl;

    cout << "Ultimo alumno registrado:\n";
    cout << left << setw(10) << "Codigo" << setw(20) << "Nombre" << setw(10) << "Genero" << setw(5) << "Edad" << "Promedio\n";
    cout << left << setw(10) << alumnos[numAlumnos-1].codigo << setw(20) << alumnos[numAlumnos-1].nombre << setw(10) << alumnos[numAlumnos-1].genero << setw(5) << alumnos[numAlumnos-1].edad << alumnos[numAlumnos-1].promedio << endl;
}

int main() {
    Alumno alumnos[MAX_ALUMNOS];
    int numAlumnos = 0;
    int opcion;
    
    do {
        cout << "\nMenu de Opciones:\n";
        cout << "1. Registrar datos de alumno\n";
        cout << "2. Ver lista de alumnos\n";
        cout << "3. Ver notas por asignatura\n";
        cout << "4. Calcular promedio de notas\n";
        cout << "5. Mostrar primer y ultimo alumno\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                registrarAlumno(alumnos, numAlumnos);
                break;
            case 2:
                verListaAlumnos(alumnos, numAlumnos);
                break;
            case 3:
                verNotasPorAsignatura(alumnos, numAlumnos);
                break;
            case 4:
                calcularPromedio(alumnos, numAlumnos);
                break;
            case 5:
                mostrarPrimeroYUltimo(alumnos, numAlumnos);
                break;
            case 6:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente.\n";
        }
    } while(opcion != 6);
    
    return 0;
}
