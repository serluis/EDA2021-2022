// Nombre del alumno .....SERGIO ALBERTO LUIS CANO
// Usuario del Juez ......VJ31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
// función que resuelve el problema
int resolver(vector<int> const& v1, vector<int> const& v2, int ini, int fin) { //O(log n)

    //casos base
    if (fin - ini == 0) {
        return ini;
    }
    if (fin - ini == 1) {
        if (v1[ini] != v2[ini]) {
            return ini;
        }
        else {
            return fin;
        }
    }
    
    //separacion esto divide el problema a la mitad cada vez que se llama
    else {

        int med = (ini + fin) / 2; //se calcula el punto medio
        /// al ser ordenados los vectores el punto medio siempre estara desplazado
        /// si es mayor o igual estara a la derecha, si no a la izq
        if (v1[med] >= v2[med]) {
            //derecha
            return resolver(v1, v2, med, fin);
        }
        else if(v1[med] < v2[med]){
            //izquierda
            return resolver(v1, v2, ini, med);
        }
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    long long int numElementos;
    cin >> numElementos;
    vector<int> v1(numElementos);
    vector<int> v2(numElementos - 1);
    for (int& e : v1) { cin >> e; }
    for (int& e : v2) { cin >> e; }
    int sol = resolver(v1, v2, 0, v1.size() - 1);
    cout << v1[sol] << endl;
}
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
    system("PAUSE");
#endif

    return 0;
}