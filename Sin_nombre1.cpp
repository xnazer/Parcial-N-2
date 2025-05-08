class NetworkManager {
private:
    SOCKET socket;
    struct sockaddr_in server_addr;

public:
    enum MessageType {
        MSG_CONNECT,
        MSG_DISCONNECT,
        MSG_CARD_PLAYED,
        MSG_ROUND_START,
        MSG_GAME_END
    };

    struct Message {
        MessageType type;
        int playerId;
        int cardId;
        char data[1024];
    };

    bool initialize() {
        // Inicialización similar al código proporcionado
        WSADATA wsaData;
        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
            return false;
        }

        socket = socket(AF_INET, SOCK_STREAM, 0);
        if (socket == INVALID_SOCKET) {
            WSACleanup();
            return false;
        }

        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(PORT);
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

        return connect(socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) != SOCKET_ERROR;
    }

    void sendMessage(MessageType type, int playerId = 0, int cardId = 0) {
        Message msg;
        msg.type = type;
        msg.playerId = playerId;
        msg.cardId = cardId;

        send(socket, (char*)&msg, sizeof(msg), 0);
    }

    Message receiveMessage() {
        Message msg;
        recv(socket, (char*)&msg, sizeof(msg), 0);
        return msg;
    }
};