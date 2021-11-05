// Nombre del alumno .....SERGIO ALBERTO LUIS CANO
// Usuario del Juez ......VJ31


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
void tipo(string s) {

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    if (!std::cin)
    {
        return false;
    }
    else {
        int s;
        cin >> s;
        
        

        cout << "Hello world!";
        // escribir sol


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
    int s;
    cin >> s;



    cout << "Hello world!";

    //while (resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif*/

    //return 0;
}