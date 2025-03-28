#ifndef JUGADOR_H
#define JUGADOR_H
using namespace std;
#include "./Mano.h"

class Jugador {
public:
    int id;
    Mano mano;
    vector<Carta> boveda;

    Jugador(int i, int cantidadCartas, vector<Carta> &mazo);
    void mostrarMano();
    void almacenarCarta(Carta c);
    int contarCartasBoveda();
    void mostrarBoveda();
};

#endif
