#include <iostream>
#include <string>

using namespace std;

struct Estudiante {
    int id;
    string nombres;
    string apellidos;
    double notas[4];
};

void calcularPromedio(Estudiante& estudiante) {
    double suma = 0;
    for (int i = 0; i < 4; ++i) {
        suma += estudiante.notas[i];
    }
    double promedio = suma / 4.0;
    cout << "El promedio de " << estudiante.nombres << " " << estudiante.apellidos << " es: " << promedio << endl;
    if (promedio > 60) {
        cout << "¡Estudiante aprobado!" << endl;
    } else {
        cout << "Estudiante reprobado." << endl;
    }
}

int main() {
    int n;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;

    Estudiante estudiantes[n];

    for (int i = 0; i < n; ++i) {
        cout << "Ingrese el ID del estudiante " << i+1 << ": ";
        cin >> estudiantes[i].id;
        cin.ignore(); // Limpiar el buffer del teclado
        cout << "Ingrese el nombre del estudiante " << i+1 << ": ";
        getline(cin, estudiantes[i].nombres);
        cout << "Ingrese el apellido del estudiante " << i+1 << ": ";
        getline(cin, estudiantes[i].apellidos);
        cout << "Ingrese las notas (separadas por espacio) del estudiante " << i+1 << ": ";
        for (int j = 0; j < 4; ++j) {
            cin >> estudiantes[i].notas[j];
        }
    }

    cout << "\nResultados:\n" << endl;

    for (int i = 0; i < n; ++i) {
        calcularPromedio(estudiantes[i]);
    }

    return 0;
}

