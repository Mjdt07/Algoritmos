#include <iostream>
#include <list>
#include <vector>
#include <cctype>

using namespace std;

// Función recursiva para calcular el factorial
int factorial(int n) {
    // Caso base: factorial de 0 es 1
    if (n == 0 || n == 1) {
        return 1;
    } else {
        // Llamada recursiva: factorial(n) = n * factorial(n-1)
        return n * factorial(n - 1);
    }
}

// Función recursiva para verificar si una cadena es un palíndrome
bool esPalindrome(const string& cadena) {
    // Caso base: una cadena de longitud 0 o 1 es siempre un palíndrome
    if (cadena.length() <= 1) {
        return true;
    } else {
        // Comparar el primer y último caracter, y llamar recursivamente con el resto de la cadena
        return (tolower(cadena[0]) == tolower(cadena[cadena.length() - 1])) &&
               esPalindrome(cadena.substr(1, cadena.length() - 2));
    }
}


// Función para calcular la secuencia de Fibonacci hasta el término n
vector<int> fibonacci(int n) {
    vector<int> secuencia;

    int a = 0, b = 1;

    for (int i = 0; i < n; ++i) {
        secuencia.push_back(a);

        int temp = a;
        a = b;
        b = temp + b;
    }

    return secuencia;
}

int main() {

int opcion;

    do {
        // Mostrar el menú
        cout << "\nMenu:\n";
        cout << "1. Operaciones\n";
        cout << "2. Calcular factorial\n";
        cout << "3. Calcular secuencia de Fibonacci\n";
        cout << "4. Verificar palabra palindrome\n";
        cout << "5. Salir\n";
        cout << "Ingrese el numero de la opcion deseada: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
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

                break;
             }


            case 2: {
                //Ej 2
                // Solicitar al usuario que ingrese un número
                int numero;
                cout << "Ingrese un numero para calcular su factorial: ";
                cin >> numero;

                // Calcular el factorial e imprimir el resultado
                if (numero < 0) {
                    cout << "El factorial no esta definido para numeros negativos.\n";
                } else {
                    int resultado = factorial(numero);
                    cout << "El factorial de " << numero << " es: " << resultado << endl;
                }

                break;
            }

            case 3: {
                //Ej 3
                // Solicitar al usuario el término hasta el cual calcular la secuencia
                int n;
                cout << "Ingrese el termino hasta el cual desea calcular la secuencia de Fibonacci: ";
                cin >> n;

                // Calcular y mostrar la secuencia de Fibonacci
                vector<int> resultado = fibonacci(n);

                cout << "Secuencia de Fibonacci hasta el termino " << n << ":\n";
                for (int num : resultado) {
                    cout << num << " ";
                }

                break;

            }

            case 4: {
                //Ej 4
                // ingreso de palabra
                    string palabra;
                    cout << "Ingrese una palabra para verificar si es un palindrome: ";
                    cin >> palabra;

                    // Verificar si la palabra es un palíndrome
                    if (esPalindrome(palabra)) {
                        cout << " Es palindrome." << endl;
                    } else {
                        cout << "No es palindrome." << endl;
                    }

                cout << endl;
                break;
            }

            case 5:
                // Salir
                cout << "Saliendo del programa.\n";
                break;
                default:
                cout << "Opción no válida. Intente nuevamente.\n";
        }

    } while (opcion != 5);


    return 0;
}

