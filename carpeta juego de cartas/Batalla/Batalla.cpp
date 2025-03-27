#include "Batalla.h"

void Batalla::iniciarRonda() {
    
    cartasLanzadas.clear();  //clear para borrar todos los elementos que se lanzaron y comenzar o iniciar una ronda
    colorInicial = -1;   //-1 para indicar que no se ha lanzado ninguna carta, por lo tanto no hay color establecido
}

void Batalla::comparar(Jugador &jugador, Carta carta) {
   
    if (cartasLanzadas.empty()) {    //se comprueba que el atributo cartasLanzadas este vacio para ejecutarse
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

    for (size_t i = 0; i < cartasLanzadas.size(); i++) {
        Jugador* jugadorActual = cartasLanzadas[i].first;  //first para usar la primer variable guardada en cartasLanzadas (Jugador)
        Carta cartaActual = cartasLanzadas[i].second;   //second para usar el segundo atributo guardado en cartasLanzadas (carta)

        if (cartaActual.color == colorInicial && cartaActual.poder > maxP) {
            maxP = cartaActual.poder;
            ganador = jugadorActual;
        }
    }

    return ganador;
}

