// Nombre del alumno .....SERGIO ALBERTO LUIS CANO
// Usuario del Juez ......VJ31


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// función que resuelve el problema
void resolver(int dato1,int dato2) {


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int dato1;
    int dato2;
    cin >> dato1;
    cin >> dato2;
    if (dato1 == 0 && dato2 == 0)
        return false;
    else {
        horas h;
        for (int i = 0; i < dato1; i++)
        {
            cin >> h;
        }
        for (int i = 0; i < dato2; i++)
        {
            //fecha2 cin
        }
        resolver(dato1,dato2);

        // escribir sol

        return true;
    }
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}

class horas {

public:
    int _h = 0;
    int _m = 0;
    int _s = 0;

    horas():_h(0),_m(0),_s(0) {}

    horas(int h, int m, int s){
        _h = h;
        _m = m;
        _s = s;
    }
    horas(horas &H) {
        try {
            if (H._h > 24 || H._m > 59 || H._s > 59) {
                throw std::invalid_argument("ERROR");
            }
            else { this->_h = H._h; this->_m = H._m; this->_s = H._s; }
        }
        catch(std::invalid_argument &e){
            throw e;
        }
    }
    bool operator<(horas &other) {
        if (this->_h < other._h) {
            return true;
        }
        else if (this->_h == other._h) {
            if (this->_m < other._m) {
                return true;
            }
            else if (this->_m == other._m) {
                if (this->_s < other._s) {
                    return true;
                }
                else { return false; }
            }
            else { return false; }
        }
        else { return false; }

        ///y ahora bonito
        /*return ((this->_h < other._h) ||
        ((this->_h == other._h) && (this->_m < other._m) ||
        ((this->_h == other._h) && (this->_m == other._m) && (this->_s < other._s))));*/
    }
};
ostream& operator << (ostream& o, horas& h) {

    if (h._h < 10) {
        o << "0" << h._h;
    }
    else {
        o << h._h;
    }
    o << ":";
    if (h._m < 10) {
        o << "0" << h._m;
    }
    else {
        o << h._m;
    }
    o << ":"; 
    if (h._s < 10) {
        o << "0" << h._s;
    }
    else {
        o << h._s;
    }
   
    return o;
};
istream& operator >> (istream& i, horas& h) {
    char descarte;
    i >> h._h;
    i >> descarte;
    i >> h._m;
    i >> descarte;
    i >> h._s;
    
    return i;
};
