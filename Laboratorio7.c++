#include <iostream>
#include <vector>

using namespace std;


struct Nodo {
    int dato;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int valor) : dato(valor), izquierda(nullptr), derecha(nullptr) {}
};

// Función para insertar un nodo en el árbol
Nodo* insertarNodo(Nodo* nodo, int valor) {
    if (nodo == nullptr) {
        return new Nodo(valor);
    }

    if (valor < nodo->dato) {
        nodo->izquierda = insertarNodo(nodo->izquierda, valor);
    } else if (valor > nodo->dato) {
        nodo->derecha = insertarNodo(nodo->derecha, valor);
    }

    return nodo;
}

// Función para imprimir en orden los nodos del árbol
void imprimirOrdenados(Nodo* nodo) {
    if (nodo != nullptr) {
        imprimirOrdenados(nodo->izquierda);
        cout << nodo->dato << " ";
        imprimirOrdenados(nodo->derecha);
    }
}

// Función para buscar un valor en el árbol
bool buscarValor(Nodo* nodo, int valor) {
    if (nodo == nullptr) {
        return false;
    }

    if (valor == nodo->dato) {
        return true;
    } else if (valor < nodo->dato) {
        return buscarValor(nodo->izquierda, valor);
    } else {
        return buscarValor(nodo->derecha, valor);
    }
}


// Función para buscar el valor mínimo en el árbol
int buscarValorMinimo(Nodo* nodo) {
    while (nodo->izquierda != nullptr) {
        nodo = nodo->izquierda;
    }
    return nodo->dato;
}

// Función para buscar el valor máximo en el árbol
int buscarValorMaximo(Nodo* nodo) {
    while (nodo->derecha != nullptr) {
        nodo = nodo->derecha;
    }
    return nodo->dato;
}

// Función para encontrar el nodo mínimo en un árbol
Nodo* encontrarMinimo(Nodo* nodo) {
    while (nodo->izquierda != nullptr) {
        nodo = nodo->izquierda;
    }
    return nodo;
}


// Función para eliminar un nodo del árbol
Nodo* eliminarNodo(Nodo* nodo, int valor) {
    if (nodo == nullptr) {
        return nodo;
    }

    // Buscar el nodo a eliminar
    if (valor < nodo->dato) {
        nodo->izquierda = eliminarNodo(nodo->izquierda, valor);
    } else if (valor > nodo->dato) {
        nodo->derecha = eliminarNodo(nodo->derecha, valor);
    } else {
        // Caso 1: Sin hijos o un solo hijo
        if (nodo->izquierda == nullptr) {
            Nodo* temp = nodo->derecha;
            delete nodo;
            return temp;
        } else if (nodo->derecha == nullptr) {
            Nodo* temp = nodo->izquierda;
            delete nodo;
            return temp;
        }

        // Caso 2: Dos hijos
        Nodo* temp = encontrarMinimo(nodo->derecha);
        nodo->dato = temp->dato;
        nodo->derecha = eliminarNodo(nodo->derecha, temp->dato);
    }

    return nodo;
}



int main() {

Nodo* raiz = nullptr;

   while (true) {
        // Mostrar el menú
        cout << "\nMenu:\n";
        cout << "1. Insertar en arbol\n";
        cout << "2. Imprimir arbol\n";
        cout << "3. Funcion busqueda\n";
        cout << "4. Funcion eliminar\n";
        cout << "5. Salir\n";

        int opcion;
        cout << "Ingrese el numero de la opcion deseada: ";
        cin >> opcion;

        switch (opcion) {

            case 1: {

                int valor;

                cout << "Ingrese numeros para construir el arbol (Escriba 0 para finalizar):\n";

                while (true) {
                    cout << "Ingrese un numero: ";
                    cin >> valor;

                    if (valor == 0) {
                        break;
                    }

                    raiz = insertarNodo(raiz, valor);
                }

                
                break;
             }


             case 2: {

                // Imprimir en orden
                cout << "Arbol en orden: ";
                imprimirOrdenados(raiz);
                cout << endl;

                
                break;

             }

             case 3: {

                int valor;

                // Buscar un valor en el árbol
                cout << "Ingrese un valor para buscar en el arbol: ";
                cin >> valor;
                if (buscarValor(raiz, valor)) {
                    cout << "El valor esta en el arbol.\n";
                } else {
                    cout << "El valor no esta en el arbol.\n";
                }

                // Buscar el valor mínimo en el árbol
                cout << "El valor minimo en el arbol es: " << buscarValorMinimo(raiz) << endl;

                // Buscar el valor máximo en el árbol
                cout << "El valor maximo en el arbol es: " << buscarValorMaximo(raiz) << endl;

                break;

             }


             case 4: {

                int valor;

                // Eliminar un nodo del árbol
                cout << "Ingrese un valor para eliminar del arbol: ";
                cin >> valor;
                raiz = eliminarNodo(raiz, valor);

                // Imprimir en orden después de la eliminación
                cout << "Arbol despues de la eliminacion: ";
                imprimirOrdenados(raiz);
                cout << endl;

                break;

             }

            case 5:{

            // Liberar la memoria antes de salir
                delete raiz;
                return 0;
            default:
                    cout << "Opcion no valida. Intente nuevamente.\n";




            }

        }   
    
    }

    return 0;

}











   

    

    
 
  



