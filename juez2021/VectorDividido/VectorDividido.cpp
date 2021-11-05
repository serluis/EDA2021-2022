// Nombre del alumno .....SERGIO ALBERTO LUIS CANO
// Usuario del Juez ......VJ31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>
using namespace std;
// función que resuelve el problema
bool resolver(const vector<int>& datos,const int & pos) { //O(N) siendo N el tamaño del vector 
    int mayorDmenores,menorDmayores;
    if (pos == datos.size() - 1) {
        return true;
    }
    else {
        mayorDmenores = datos[0];
        menorDmayores = datos[pos+1];
        for (int i = 0; i < pos; i++) {
            if (mayorDmenores < datos[i + 1]) {
                mayorDmenores = datos[i+1];
            }
        }
        for (int i = pos+1; i < datos.size()-1; i++) {
            if (menorDmayores > datos[i + 1]) {
                menorDmayores = datos[i+1];
            }
        }
        if (mayorDmenores < menorDmayores) {
            return true;
        }
        else {
            return false;
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int l,pos,temp;
    std::cin >> l;
    std::cin >> pos;
    vector <int> datos;
    for (int i = 0; i < l; ++i) {
        cin >> temp;
        datos.push_back(temp);
    }

    bool sol = resolver(datos,pos);
    
    
    // escribir sol
    if (sol) {
        cout << "SI" << endl;
    }
    else {
        cout << "NO" << endl;
    }

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