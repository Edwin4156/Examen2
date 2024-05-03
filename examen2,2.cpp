#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Estudiante {
    int id;
    string nombres;
    string apellidos;
    double notas[4];
    double promedio;
    string resultado;
};

void crearEstudiante() {
    ofstream archivo("notas.dat", ios::binary | ios::app);
    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }

    Estudiante estudiante;

    cout << "Ingrese el ID del estudiante: ";
    cin >> estudiante.id;
    cin.ignore(); // Limpiar el buffer del teclado
    cout << "Ingrese el nombre del estudiante: ";
    getline(cin, estudiante.nombres);
    cout << "Ingrese el apellido del estudiante: ";
    getline(cin, estudiante.apellidos);
    cout << "Ingrese las notas (separadas por espacio) del estudiante: ";
    for (int i = 0; i < 4; ++i) {
        cin >> estudiante.notas[i];
    }
    double suma = 0;
    for (int i = 0; i < 4; ++i) {
        suma += estudiante.notas[i];
    }
    estudiante.promedio = suma / 4.0;
    estudiante.resultado = (estudiante.promedio > 60) ? "Aprobado" : "Reprobado";

    archivo.write(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante));
    archivo.close();
}

void leerEstudiantes() {
    ifstream archivo("notas.dat", ios::binary);
    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }

    Estudiante estudiante;
    while (archivo.read(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante))) {
        cout << "ID: " << estudiante.id << endl;
        cout << "Nombres: " << estudiante.nombres << endl;
        cout << "Apellidos: " << estudiante.apellidos << endl;
        cout << "Notas: ";
        for (int i = 0; i < 4; ++i) {
            cout << estudiante.notas[i] << " ";
        }
        cout << endl;
        cout << "Promedio: " << estudiante.promedio << endl;
        cout << "Resultado: " << estudiante.resultado << endl;
        cout << endl;
    }

    archivo.close();
}

int main() {
    int opcion;
    do {
        cout << "1. Crear estudiante" << endl;
        cout << "2. Leer estudiantes" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                crearEstudiante();
                break;
            case 2:
                leerEstudiantes();
                break;
            case 3:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 3);

    return 0;
}

