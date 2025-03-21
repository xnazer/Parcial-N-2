int main() {
    Carta unaCarta(2, 2);
    unaCarta.mostrar();
    cout << endl;

    Mazo baraja;
    cout << "Mazo original: " << endl;
    baraja.mostrar();
    cout << endl;

    baraja.barajar();  // Barajar el mazo
    cout << "Mazo barajado: " << endl;
    baraja.mostrar();

    return 0;
}
