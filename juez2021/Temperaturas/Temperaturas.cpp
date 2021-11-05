// Nombre del alumno .....SERGIO ALBERTO LUIS CANO
// Usuario del Juez ......VJ31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>
using namespace std;
// función que resuelve el problema
pair<int,int> resolver(const vector<int> & datos) { //O(N) siendo N el tamaño del vector 
    pair<int, int> picVal = { 0, 0 };
    for (int i = 1; i < datos.size() - 1; i++) {
        if (datos[i] < datos[i + 1]  && datos[i] < datos[i-1] ) {
            picVal.second++;
        }
        if (datos[i] > datos[i + 1]  && datos[i] > datos[i-1] ) {
            picVal.first++;
        }
    }
    return picVal;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int numCasos;
    std::cin >> numCasos;
    int temp;
    vector <int> temps;
    for (int i = 0; i < numCasos; ++i) {
        cin >> temp;
        temps.push_back(temp);
    }

    pair <int, int> sol = resolver(temps);
    int pico, valle;
    pico = sol.first;
    valle = sol.second;
    // escribir sol
    cout << pico << " " << valle << endl;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
/*#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif */


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif*/

    return 0;
}