// Nombre del alumno .....SERGIO ALBERTO LUIS CANO
// Usuario del Juez ......VJ31

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;

// función que resuelve el problema
bool resolver(const vector<int> &datos, const int &k, int ini , int fin) {
    // Coste O(n) Siendo n la longitud del vector
    // se hacen 2 llamadas recursivas con tamaño mitad
    // y ningun coste extra no constante
    // En la plantilla de resolucion de recurrencias por division a=2 b=2 k=0
    
    if (fin - ini < 1) {
        return true;
    }
    if (fin - ini == 1) {
        if ( abs(datos[ini] - datos[fin]) >= k) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        int med = (ini+fin)/2;
        bool iz = resolver(datos, k, ini, med); 
        bool der = resolver(datos, k, med+1, fin); 
        bool dis = abs(datos[ini] - datos[fin]) >= k;
        return iz && der && dis;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
//v[0]=true
bool resuelveCaso() {
    // leer los datos de la entrada
    int largo;
    cin >> largo;
    if (!std::cin) {
        return false;
    }
    else {
        int k, temporal;
        vector<int> datos;        
        cin >> k;
        for (int i = 0; i < largo; i++) {
            cin>>temporal;
            datos.push_back(temporal);
        }
        int ini = 0, fin = datos.size();
        bool sol = resolver(datos, k, ini, fin-1);

        if (sol) {
            cout << "SI" << endl;
        }
        else {
            cout << "NO" << endl;
        }
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