#ifndef BATALLA_H
#define BATALLA_H
using namespace std;
#include "Jugador.h"
#include <vector>

class Batalla {
    public:
    
    int colorInicial = -1;
    vector<pair<Jugador*, Carta>> cartasLanzadas;
    bool primeraCarta = true;

    void iniciarRonda();
    void comparar(Jugador &jugador, Carta carta);
    Jugador* definirGanadorRonda();
};

#endif
