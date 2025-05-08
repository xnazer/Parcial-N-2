class Juego {
private:
    NetworkManager network;
    vector<Jugador> jugadores;
    Batalla btla;
    Mazo mazo;
    int miId;
    
public:
    Juego(bool esServidor, int id) : miId(id) {
        if (esServidor) {
            iniciarComoServidor();
        } else {
            conectarAlServidor();
        }
    }

    void jugar() {
        if (!network.initialize()) {
            throw runtime_error("Error al inicializar red");
        }

        while (true) {
            Message msg = network.receiveMessage();
            
            switch (msg.type) {
                case NetworkManager::MSG_ROUND_START:
                    iniciarRonda();
                    break;
                    
                case NetworkManager::MSG_CARD_PLAYED:
                    procesarCartaJugada(msg.playerId, msg.cardId);
                    break;
                    
                case NetworkManager::MSG_GAME_END:
                    terminarJuego();
                    return;
            }
        }
    }

    void lanzarCarta(int cartaId) {
        network.sendMessage(NetworkManager::MSG_CARD_PLAYED, miId, cartaId);
    }
};