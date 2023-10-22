#include <iostream>
#include <list>

using namespace std;

int main() {
    // Crea una lista para almacenar los números
    list<double> numeros;

    // Solicita la cantidad de números
    double cantidad;
    cout << "Ingrese la cantidad de numeros: ";
    cin >> cantidad;

    // Solicita el ingreso de los números y los almacena en la lista
    for (int i = 0; i < cantidad; ++i) {
        double numero;
        cout << "Ingrese el numero " << i + 1 << ": ";
        cin >> numero;

        // Agregar el número al final de la lista
        numeros.push_back(numero);

    }

    // Calcular la suma de los números
    double suma = 0;
    double multiplicacion = 1;
    double promedio = 2;

    for (double num : numeros) {
        suma += num;
        multiplicacion *= num;
    }
    
     promedio = suma/cantidad;

    cout << "\nLa suma de los numeros es: " << suma << endl;
    cout << "\nLa multiplicacion de los numeros es: " << multiplicacion << endl;
    cout << "\nEl promedio de los numeros es: " << promedio << endl;




    return 0;
}

