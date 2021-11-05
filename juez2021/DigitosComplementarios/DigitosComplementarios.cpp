// Nombre del alumno .....SERGIO ALBERTO LUIS CANO
// Usuario del Juez ......VJ31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;

int complementario(int a) {
   
    return  9 - a;
}
int resuelveCasoA(int dato) {
        
    if (dato > 10) {
        int digit = dato % 10;
        dato /= 10;
        return complementario(digit) + resuelveCasoA(dato)*10;
    }
    else {
        return 9-dato;
    }
}
int resuelveCasoB(const int & dato,int & newPot) {//la funcion invierte el orden introduce la potencia
    
    if (dato > 10) {
        int pot;
        int pre = resuelveCasoB(dato / 10, pot);
        int digit = dato % 10;
        newPot = 10 * pot;
        return  (pot * digit) + pre;

    }
    else {
        newPot = 10;
        return dato;        
    }
}

void escribe(const int& orden,const int& desorden) {
    cout << orden << " " << desorden << endl;
}

int main()
{
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) {
        int dato;
        std::cin >> dato;
        
            int pot=1;
            int parcial = resuelveCasoA(dato);
            escribe(parcial,
                resuelveCasoB(parcial,pot));
        
    }
}

/*


void fact(int n,int&res){
 if(n==0){
     res =1;
 }
 else{
     int aux;
     fact(n-1,aux);
     res= aux *n;
 }




}*/
