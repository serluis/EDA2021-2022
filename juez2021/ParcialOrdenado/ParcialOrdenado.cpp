bool parcial(vectorint& const v, int ini, int fin, int &min,int&max) { //NLOGN
	int n = ...
		if (n == 1) {
			
			min v[ini];...
			
			
			return true
		}
		else
			bool ordIzq, ordDer;
	int mitad= ...
	int miniIz, miniDR, maxDer, maxIz;



	ordIz = parcial(v, ini, mitad,miniIz,maxiz);
	ordDer = parcial(v, mitad, fin,,miniDR,maxDer);
	
	min = minimo(miniIz, miniDR);
	max = maximo(maxIz, maxDer);
		

	comprobar;
	return ordIz && OrdDer && miniIz<=miniDR && maxDer >= maxIz;
}