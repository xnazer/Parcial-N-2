#ifndef CARTA_H
#define CARTA_H
using namespace std;
#include <iostream>
#include <vector>

#define BG_RED "\x1B[41m"
#define BG_BLUE "\x1B[44m"
#define BG_BLACK "\x1B[40m"
#define BG_GREEN "\x1B[42m"
#define WHITE "\x1B[37m"
#define RESET "\x1b[0m"

class Carta {
    
public:
    string paleta[4] = {BG_RED, BG_BLUE, BG_BLACK, BG_GREEN};
    int poder = 0;
    int color = 0;
    Carta() {};
    Carta(int p, int c);
    void mostrar();
};

#endif
