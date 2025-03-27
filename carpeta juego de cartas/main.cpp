#include "Juego.h"
using namespace std;
int main() {
    int nJugadores;
    do {
        cout << "Ingrese el número de jugadores (2, 3 o 4): ";
        cin >> nJugadores;
    } while (nJugadores < 2 || nJugadores > 4);

    Juego prueba0(nJugadores);
    prueba0.jugar();

    return 0;
}
