// Nombre del alumno .....SERGIO ALBERTO LUIS CANO
// Usuario del Juez ......VJ31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
//#include <list>
//#include <queue>
//#include <deque>
#include <stack>

using namespace std;


// función que resuelve el problema
bool resolver(string &datos) {
    bool equi = true;
    stack<char> car;
    int i = 0;
    while  (i < datos.length() && equi == true) {
        char c;
        c = datos[i];
        switch (c)
        {
        case '(':
           car.push(c);           
            break;
        case ')':
            if (car.empty()) {
                equi = false;
            }
            else if (!car.empty()) {
                if (car.top() == '(') {
                    car.pop();
                }
                else {
                    equi = false;
                }
            }
            break; 
        case '[':
            car.push(c);
            break; 
        case ']':
            if (car.empty()) {
                equi = false;
            }
            else if (!car.empty()) {
                if (car.top() == '[') {
                    car.pop();
                }
                else {
                    equi = false;
                }
            }
            break; 
        case '{':
            car.push(c);
            break; 
        case '}':
            if (car.empty()) {
                equi = false;
            }
            else if (!car.empty()) {
                if (car.top() == '{') {
                    car.pop();
                }
                else {
                    equi = false;
                }
            }
            break;
        default:
            break;
        }
        i++;
    }
    if (car.empty())
        return equi;
    else
        return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    string datos;
    getline(cin, datos);
    if (!std::cin)
        return false;

    bool sol = resolver(datos);

    if (sol) {
        cout << "SI" << endl;
    }
    else {
        cout << "NO" << endl;
    }


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