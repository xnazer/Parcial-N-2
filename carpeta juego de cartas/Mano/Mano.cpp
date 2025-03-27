#include "Mano.h"
#include <iostream>

using namespace std;



Mano::Mano(int cantidad, vector<Carta> &mazo) {
    for (int i = 0; i < cantidad; i++) {
        cartas.push_back(mazo.back());
        mazo.pop_back();
    }
}

void Mano::mostrar() {
    for (size_t i = 0; i < cartas.size(); i++) {
        cout << i + 1 << ". ";
        cartas[i].mostrar();
    }
    cout << endl;
}

Carta Mano::lanzar(int ncartasd) {
    Carta cs = cartas[ncartasd];
    cartas.erase(cartas.begin() + ncartasd);
    return cs;
}
