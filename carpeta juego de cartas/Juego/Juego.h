#ifndef JUEGO_H
#define JUEGO_H
using namespace std;
#include "Mazo.h"
#include "Batalla.h"

class Juego {
public:
    vector<Jugador> jugadores;
    Batalla btla;
    Mazo mazo;
    int numJugadores;

    Juego(int n);
    void jugar();
    void determinarGanador();
};


#endif
