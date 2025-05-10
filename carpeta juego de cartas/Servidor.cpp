#include ".cpp y .h/Juego.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#define PUERTO 8080
#define MAX_JUGADORES 4

using namespace std;

int main() {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    SOCKET listener = socket(AF_INET, SOCK_STREAM, 0);
    
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(PUERTO);
    hint.sin_addr.s_addr = INADDR_ANY;
    
    bind(listener, (sockaddr*)&hint, sizeof(hint));
    listen(listener, SOMAXCONN);

    cout << "Esperando conexiones de jugadores..." << endl;

    vector<SOCKET> clientes;
    int numJugadores;
    
    // Obtener número de jugadores del host
    cout << "Ingrese el número de jugadores (2-4): ";
    cin >> numJugadores;
    while (numJugadores < 2 || numJugadores > 4) {
        cout << "Número inválido. Intente nuevamente: ";
        cin >> numJugadores;
    }

    // Esperar conexiones de clientes
    while (clientes.size() < numJugadores) {
        sockaddr_in client;
        int clientSize = sizeof(client);
        
        SOCKET clientSocket = accept(listener, (sockaddr*)&client, &clientSize);
        if (clientSocket != INVALID_SOCKET) {
            clientes.push_back(clientSocket);
            
            char host[NI_MAXHOST];
            inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
            cout << "Conectado con " << host << endl;
        }
    }

    // Iniciar juego
    Juego juego(numJugadores);
    juego.iniciarPartidaMultijugador(clientes);

    // Cerrar conexiones
    for (auto& client : clientes) {
        closesocket(client);
    }
    closesocket(listener);
    WSACleanup();

    return 0;
}

