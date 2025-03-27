#ifndef MANO_H
#define MANO_H
using namespace std;
#include "Carta.h"
#include <vector>

class Mano {
    public:
    vector<Carta> cartas;
    
    Mano() {}
    Mano(int cantidad, vector<Carta> &mazo);
    void mostrar();
    Carta lanzar(int ncartas);
};


#endif
