// SERGIO ALBERTO LUIS CANO
// VJ31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
//#include "SetOfInts1.h"
#include <set>
using namespace std;
int conversor(string entrada) {                 // O(n) donde n=caracteres del string
    return stoi(entrada);
}
int elevado(int a) {                            // O(1)
    return a * a;
}
int sumador(vector<int> ristra) {               // O(n) donde n=largo del vector
    int suma = 0;
    for (int i = 0; i < ristra.size(); i++) {
        suma += ristra[i];
    }
    return suma;
}
vector<int> descomponedor(int largo) {          // O(a*n) donde: a=caracteres del string, n=largo del vector
    vector<int>separado;
    string datos = to_string(largo);
    int it = 0;
    while (it < datos.size()) {
        separado.push_back(datos[it] - 48);
        it++;
    }
    return separado;
}
void elevador(vector<int>& separado) {           // O(n) //esta haciendo copia no debe
    for (int i = 0; i < separado.size(); i++) {
        separado[i] = elevado(separado[i]);
    }
}
void recursivo(set<int>& historico, int num) {    //esta haciendo copia no debe    
    vector<int>separado = descomponedor(num);
    elevador(separado);
    int suma = sumador(separado);
    if (historico.find(suma) != historico.end()){
        if (suma == 1) {
            historico.insert(1);
            cout << 1;
        }
        else {
            historico.insert(suma);
            cout << suma << " ";
            historico.insert(0);
            cout << 0;
        }
    }
    else {
        historico.insert(suma);
        cout << suma <<" ";
        recursivo(historico, suma);
    }
}
// función que resuelve el problema
set<int> resolver(string datos) {
    set<int> historico;
    int d = conversor(datos);       // Paso del valor inicial a Int
    historico.insert(d); //es el primero y caso especial
    cout << datos << " ";
    recursivo(historico, d);
    return historico;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    string dato;
    cin >> dato;
    if (!std::cin)
        return false;

    set<int> sol = resolver(dato);
    // escribir sol
   
    cout << endl;
    return true;

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