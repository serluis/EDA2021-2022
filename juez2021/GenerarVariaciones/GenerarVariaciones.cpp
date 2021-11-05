// Nombre del alumno .....Sergio Alberto Luis Cano
// Usuario del Juez ......VJ31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

bool esSolucion(int iteradorAlfabeto, int largoPalabra) {
    return iteradorAlfabeto == (largoPalabra - 1);//es -1 para que no salga de rango
}

/// <summary>
/// //transforma el vector de la palabra a cout
/// </summary>
/// <param name="solucion">palabra obtenida</param>
/// <param name="largoPalabra">largo disponible</param>
void tratarSolucion(vector<int> solucion, int largoPalabra) { 
    //cout << "Solucion: ";
    for (int i = 0; i < largoPalabra; i++) {
        char a = solucion[i] + 97;
        cout << a;
    }
    cout << endl;
}

/// Valora si es valida la palabra
bool esValida(vector<int> solucion, int iteradorAlfabeto) {
    int i = 0;
    //comprueba si esta dentro del alfabeto (y) mientras la letra en la posicion alfabetica es diferente de la letra en la posicion iterada
                                            /// comprueba que la letra no esta repetida
    while (i < iteradorAlfabeto && solucion[i] != solucion[iteradorAlfabeto]) i++;
    return i == iteradorAlfabeto;//devuelve si la iteracion es igual a la letra iteradora
}
// función que resuelve el problema
void variaciones(vector<int>& solucion, int iteradorAlfabeto, int letrasDelAlfabetoSeleccionables, int largoPalabra) {
    //bucle que itera por el trozo de alfabeto disponible
    for (int letraActual = 0; letraActual < letrasDelAlfabetoSeleccionables; letraActual++) {
        //mete en la solucion la letra por la que vamos
        solucion[iteradorAlfabeto] = letraActual;
        if (esValida(solucion, iteradorAlfabeto)) {//comprueba si es valida
            if (esSolucion(iteradorAlfabeto, largoPalabra)) {//comprueba si ha terminado de rellenar
                tratarSolucion(solucion, largoPalabra);//saca por pantalla la solucion
            }
            else {
                //si no cumple se pasa a la siguiente letra
                variaciones(solucion, iteradorAlfabeto + 1, letrasDelAlfabetoSeleccionables, largoPalabra);
            }
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int letrasDelAlfabetoSeleccionables; // cuantas se cogen del alfabeto.
    cin >> letrasDelAlfabetoSeleccionables; //=n
    if (!std::cin)
        return false;
    int largoPalabra; //como de larga sera la largoPalabra
    cin >> largoPalabra; // =m
    vector<int> sol(largoPalabra); //la solucion solo puede tener este largo
    int iteradorAlfabeto = 0; //por cual letra voy
    //enum alfa { nulo,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z};
    variaciones(sol, iteradorAlfabeto, letrasDelAlfabetoSeleccionables, largoPalabra);
    
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