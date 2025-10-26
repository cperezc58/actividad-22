#include <iostream>
#include <cstring>  // Para strlen
using namespace std;

// Estructura para manejar una palabra
struct Palabra {
    char texto[100];   // palabra original
    char cifrado[100]; // palabra cifrada
};

// Función para aplicar Cifrado César (ejemplo con ROT13)
void cifrarCesar(Palabra &p, int desplazamiento) {
    int n = strlen(p.texto);
    for (int i = 0; i < n; i++) {
        char c = p.texto[i];

        if (c >= 'A' && c <= 'Z') {  // Mayúsculas
            p.cifrado[i] = ( (c - 'A' + desplazamiento) % 26 ) + 'A';
        }
        else if (c >= 'a' && c <= 'z') { // Minúsculas
            p.cifrado[i] = ( (c - 'a' + desplazamiento) % 26 ) + 'a';
        }
        else {
            p.cifrado[i] = c; // Otros caracteres no se modifican
        }
    }
    p.cifrado[n] = '\0'; // Cierre de cadena
}

int main() {
    Palabra palabra;

    cout << "Ingrese una palabra: ";
    cin >> palabra.texto;

    // Aplicamos ROT13 (desplazamiento 13)
    cifrarCesar(palabra, 13);

    cout << "Texto original: " << palabra.texto << endl;
    cout << "Texto cifrado : " << palabra.cifrado << endl;

    system("pause");
}
