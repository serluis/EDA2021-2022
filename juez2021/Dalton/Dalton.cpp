// Nombre del alumno .....SERGIO ALBERTO LUIS CANO
// Usuario del Juez ......VJ31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool buscaDalton(const vector<int>& alturas) { ///Coste O(N)
    int contador = 0;
    bool fin = false, valido = true;
    if (alturas[contador] == alturas[contador + 1]) {
        return false;
    }
    bool mayor = alturas[contador] < alturas[contador + 1];
    contador++;

    //Sacar factor comun del while y meter dentro el if de mayor

    if (mayor) {
        while (!fin && valido) {
            if (contador == alturas.size() - 1) {
                fin = true;
            }
            else {
                valido = alturas[contador] < alturas[contador + 1];
                contador++;
            }
        }
    }
    else { //menor

        while (!fin && valido) {
            if (contador == alturas.size() - 1) {
                fin = true;
            }
            else {
                valido = alturas[contador] > alturas[contador + 1];
                contador++;
            }

        }
    }
    if (valido == true && fin == true) {
        return true;
    }
    else {
        return false;
    }
}
bool resuelveCaso() {
    // leer los datos de la entrada
    int numcaso;
    cin >> numcaso;
    if (numcaso == 0) {
        return false;
    }
    else {
        int val;
        vector <int> alturas;
        for (int i = 0; i < numcaso; i++) {
            cin>>val;
            alturas.push_back(val);
        }
        if (buscaDalton(alturas)) {
            cout << "DALTON" << endl;
        }
        else {
            cout << "DESCONOCIDOS" << endl;
        }
        return true;
    }

}
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
/*#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif */

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif*/

//return 0;
}