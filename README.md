//Pregunta 1//

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
        "fiebre", "tos", "dolor de cabeza", "nauseas", "dolor de garganta",
        "congestion", "fatiga", "escalofrios", "dolor muscular", "perdida de apetito"
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
    cout << "Por favor, responda a las siguientes preguntas con '1' para Si y '0' para No:\n";
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
        cout << "No se puede emitir un diagnostico fiable con los sintomas proporcionados.\n";
    }

    return 0;
}


//Pregunta 2//

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


//Pregunta 3//

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
