#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


bool anagramas( string& cad1, string& cad2) { // O (2 * ( N * log 2 N) + N) siendo N el tamaño de las cadenas.
    if (cad1.size() != cad2.size()) {
        return false;
    }
    else {
        sort(cad1.begin(), cad1.end()); //O(N*log2n)
        sort(cad2.begin(), cad2.end()); //O(N*log2n)

        // Compare sorted strings
        for (int i = 0; i < cad1.size(); i++) { //O(N)
            if (cad1[i] != cad2[i]) {
                return false;
            }
        }

        return true;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    string word1, word2;
    cin >> word1 >> word2;
    cout << (anagramas(word1, word2) ? "SI" : "NO") << endl;
}

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}