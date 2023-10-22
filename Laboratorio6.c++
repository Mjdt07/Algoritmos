#include <iostream>
#include <list>

int main() {
    // Crear una lista para almacenar los números
    std::list<int> numeros;

    // Solicitar al usuario que ingrese la cantidad de números
    int cantidad;
    std::cout << "Ingrese la cantidad de números: ";
    std::cin >> cantidad;

    // Solicitar al usuario que ingrese los números y almacenarlos en la lista
    for (int i = 0; i < cantidad; ++i) {
        int numero;
        std::cout << "Ingrese el número " << i + 1 << ": ";
        std::cin >> numero;

        // Agregar el número al final de la lista
        numeros.push_back(numero);
    }

    // Mostrar los números ingresados
    std::cout << "Los números ingresados son: ";
    for (int num : numeros) {
        std::cout << num << " ";
    }

    return 0;
}

