#include "Carta.h"
#include <iostream>

using namespace std;



Carta::Carta(int p, int c) {
    color = c;
    poder = p;
}

void Carta::mostrar() {
    cout << WHITE << paleta[color] << poder << RESET << " ";
}
