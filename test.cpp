
#include <iostream>


class Figura {
    public:
    virtual double calcularArea() = 0; /* Método virtual puro o abstracto */
    virtual double calcularPerimetro() = 0; /* Método virtual puro o abstracto */
};

class Figura_t: public Figura {
    int numLados;
    public:
    Figura_i(int lados) { numLados = lados; }
    int getNumLados() { return numLados; }
    int setNumLados(int nuevoNum) { numLados = nuevoNum; }
    double calcularArea() {}
    double calcularPerimetro() {}
};

class Triangulo: public Figura_t {
    int ancho;
    int alto;
    public:
    double calcularArea() { return 1; }
    double calcularPerimetro() { return 1; }
};

class Rectangulo: public Figura_t {
    int ancho;
    int alto;
    public:
    double calcularArea() { return 1; }
    double calcularPerimetro() { return 1; }
};


int main () {
    int x = 10;
    std::cout << (x++);
}



