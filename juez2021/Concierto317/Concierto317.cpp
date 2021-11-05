// Nombre del alumno .....Sergio Alberto Luis Cano
// Usuario del Juez ......VJ31

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

void comparaSol(int& solAct, int posible) {
    if (solAct < posible) {
        solAct = posible;
    }
}
int sumaSol(vector<int> &sol) {//([2][0]=160,[1][1]=20,[0][2]=30)=210
    int suma = 0;
    for (int i = 0; i < sol.size(); i++) {
        suma += sol[i];
    }
    return suma;
}
// función que resuelve el problema
void resolver(const vector<vector<int>> &beneficios,
    const vector<vector<bool>> &consentimientos,const int &numGrupos,
    int&sol, int artista,int aceptacion) {
    for (int itA = 0; itA < numGrupos; itA++) {
        
        for (int itB = 0; itB < numGrupos; itB++) {
            if (itA != itB) {//ignora la diagonal
                if (consentimientos[itA][itB]) {

                    //no se como tratar con la matriz de bool
                    //para incorporar o no la cantidad de donaciones
                    //a un posible vector de ints
                }
            }            
        }

    }
}

void resuelveCaso() {
   
    int n;
    cin >> n;
    vector<vector<int>> beneficios(n, vector<int>(n));
    vector<vector<bool>> consentimientos(n, vector<bool>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> beneficios[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            int b;
            cin >> b;
            consentimientos[i][j] = b;
        }
    int sol = -1;
    int artista = 0, aceptacion = 0;
    resolver(beneficios,consentimientos,n,sol,artista, aceptacion);
    // salida
    if (sol == -1) {
        cout << "NEGOCIA CON LOS ARTISTAS" << endl;
    }
    else {
        cout << sol << endl;
    }   
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
