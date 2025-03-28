#include "./Jugador.h"
#include <iostream>

using namespace std;

Jugador::Jugador(int i, int cantidadCartas, vector<Carta> &mazo) {
    this->id = i;
    this->mano = Mano(cantidadCartas, mazo);
}

void Jugador::mostrarMano() {
    cout << "Jugador " << id << " - Mano: ";
    mano.mostrar();
}

void Jugador::almacenarCarta(Carta c) {
    boveda.push_back(c);
}

int Jugador::contarCartasBoveda() {
    return boveda.size();
}

void Jugador::mostrarBoveda() {
    cout << "Bodega del Jugador " << id << " (" << contarCartasBoveda() << " cartas): ";
    for (Carta c : boveda) {
        c.mostrar();
    }
    cout << endl;
}
