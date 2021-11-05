/* Un primer ejemplo: todas las largoPalabras posibles
2. Esquema general y variante con marcas
3. ejemplo coloreado de mapa
4. ejemplolas n reinas
5. variante esquema para obtener solo una solucion: la primera
6. ejemplo laberinto
7. Optimizacion ejemplo problema del viajante
8. Variante esquema para obtener mejor solucion
9. poda por estimacion
10. ejemplo problema de la mochila

anagramas de long n con m letras distintas
n=3
m=4 -> A={a,b,c,d}
tupla solucion [s0,s1,...sn-1]
donde s es la letra en posicion i-esima con si € A

void largoPalabrasRec(soluc,n,m,k,vector<bool>& usadas){
	for(char='a';c<'a'+m;c++){
		soluc[k]=c;
		if(!usadas[c-'a']){

			if(k==n-1){
				cout<<soluc;
			}
			else{
				usadas[c-'a'] = true;
				largoPalabrasRec(soluc,n,m,k+1);
				usadas[c-'a'] = false;
			}
		}
}
bool usada(...){
int i=0;
bool esta = false;
while(!esta && i<k){...}

void backtracking(vector<T>& sol, int n, int k, ...m){
	for(auto c: candidatos(k)){
		sol[k] = c;
		if(valida(sol,k,n,...)){
			if(esSol(sol,k,n,...)){
				tratarSol(sol);
			}
			else{
				marcar(...);
				backtracking(sol,n,k+1, ...m);
				desmarcar(...);
			}
		
		}
	}


}
bool esValida(...,mapa,sol,int k){
	bool valida=true;
	int i=0;
	while(valida&& i<k){
		if(mapa[i][k]&& sol[i] == sol[k]){
			valida = false;
		}
		i++;
	}
	return valida;
}

void coloreado(soluc,int n, int m, int k, const Mapa& mapa){
	for(int color=0;color<m;++color){
		soluc[k] = color;
		if(esValida(...)){
			if(k==n-1){
				cout<<soluc;
			}
		}
		else{
			coloreado(soluc,n,m,k+1);
		}	
	}
}
// Se hace una matriz de adyacencia
 0 1 2 3
0x t t f
1t x f t
2t f x f
3
using Mapa = vector<vector<bool>>;
//if(m[0],[1]) suponinedo Mapa m;

int main(){
	cin>>n>>m;
	Mapa mapa(n,vector<bool>(n,false));
	coloreado(soluc,n,m,0,mapa);


}
////////////////////////////////////////////////////////////////////////////


void laberintoOpt(soluc,int n,int k, const Mapa& mapa,Mapa& mapa, 
					int logitud,int & mejorLong){
	for(int dir=0; dir < 4 &&; ++dir){
		soluc[k] = sigDir(dir,soluc[k-1]);
		if(esValida(mapa,soluc[k],n,visitadas)){
			longitud++;
			if(soluc[k].fila == n-1 && ...){
				cout<<soluc;
				if(longitud <mejorLong)
					mejorLong = longitud;
			}
			else{
				if(longitud < mejorLong){
					visitadas[soluc[k].fila][soluc[k].col = true;
					laberintoOpt(soluc,n,k+1,...);
					visitadas[soluc[k].fila][soluc[k].col = false;
				}
			}
		}
	}
}

cambio de operador

Set1<T>&operator=(Set1<T>const& other){

	if(this!=&other){
		libera();
		copia(other);
	}
	return *this;
}


*/