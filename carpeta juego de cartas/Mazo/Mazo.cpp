#include "Mazo.h"
#include <algorithm>
#include <random>

using namespace std;
Mazo::Mazo() {
    cartas.resize(36);
    int indice = 0;
    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j < 4; j++) {
            cartas[indice++] = Carta(i, j);
        }
    }
    barajar();
}

void Mazo::barajar() {
    int idUno, idDos;
    for (int i = 0; i < 25; i++) {
        idUno = rand() % cartas.size();
        idDos = rand() % cartas.size();
        swap(cartas[idUno], cartas[idDos]);
    }
}

Carta Mazo::repartir() {
    int indice = rand() % cartas.size();
    Carta ca = cartas[indice];
    cartas.erase(cartas.begin() + indice);
    return ca;
}

void Mazo::mostrar() {
    int indice = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 4; j++) {
            indice = (4 * i) + j;
            cartas[indice].mostrar();
        }
    }
}
