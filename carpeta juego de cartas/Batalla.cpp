#include "./Batalla.h"

void Batalla::iniciarRonda() {
    
    cartasLanzadas.clear();  
    colorInicial = -1;   
}

void Batalla::comparar(Jugador &jugador, Carta carta) {
   
    if (cartasLanzadas.empty()) {    
        colorInicial = carta.color;
    }
    cartasLanzadas.push_back({&jugador, carta});
}

Jugador* Batalla::definirGanadorRonda() {
    if (cartasLanzadas.empty()) {
        return 0; 
    }

    Jugador* ganador = 0;
    int maxP = 0;

    for (int i = 0; i < cartasLanzadas.size(); i++) {
        Jugador* jugadorActual = cartasLanzadas[i].first;
        Carta cartaActual = cartasLanzadas[i].second;   

        if (cartaActual.color == colorInicial && cartaActual.poder > maxP) {
            maxP = cartaActual.poder;
            ganador = jugadorActual;
        }
    }

    return ganador;
}

