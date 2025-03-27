#ifndef MAZO_H
#define MAZO_H
using namespace std;
#include "Carta.h"
#include <vector>

class Mazo {
public:
    vector<Carta> cartas;
    Mazo();
    void barajar();
    Carta repartir();
    void mostrar();
};

#endif
