#include "Juego.h"
#include <iostream>

using namespace std;

Juego::Juego(int n) {
    
    this->numJugadores = n;
    this->mazo = mazo;
    int cartasPorJugador = 36 / n;
    for (int i = 0; i < n; i++) jugadores.push_back(Jugador(i + 1, cartasPorJugador, mazo.cartas));
    
}

void Juego::jugar() {
    
    for (int ronda = 0; ronda < 3; ronda++) {
        cout << "\n--- Ronda " << ronda + 1 << " ---\n";
        std::cout << " " << std::endl;
        btla.iniciarRonda();
        for (Jugador &player : jugadores) {
            player.mostrarMano();
            int eleccion;
            do {
                cout << "Jugador " << player.id << ", elige una carta para lanzar (1 - " << player.mano.cartas.size() << "): ";
                cin >> eleccion;
            } while (eleccion < 1 || eleccion > player.mano.cartas.size());
            
            Carta lanzada = player.mano.lanzar(eleccion - 1);
            cout << "Jugador " << player.id << " lanza: "; lanzada.mostrar(); cout << endl;
            btla.comparar(player, lanzada);
        }
        Jugador* ganadorRonda = btla.definirGanadorRonda();
        if (ganadorRonda) {
            cout << " " << endl;
            cout << "---Ganador de la ronda: Jugador ---" << ganadorRonda->id << "\n";
            cout <<  " "<< endl;
            cout << " " << endl;
            for (auto &entrada : btla.cartasLanzadas) {
                ganadorRonda->almacenarCarta(entrada.second);
            }
        } 
    }
    
    determinarGanador();
}

void Juego::determinarGanador() {
    for (Jugador &player : jugadores) {
        player.mostrarBoveda();
    }
    Jugador *ganador = &jugadores[0];
    for (Jugador &player : jugadores) {
        if (player.contarCartasBoveda() > ganador->contarCartasBoveda()) {
            ganador = &player;
        }
    }
    cout <<" "  << endl;
    cout << "\nEl ganador final es el Jugador " << ganador->id << " con " << ganador->contarCartasBoveda() << " cartas en la bodega!\n";
}