#include "Gramatica.h"

int main() {
	
	ifstream baga("din.txt");
	ofstream exit("unde.txt");
	Gramatica g(baga);
	g.generareGramatica(exit);
	
	return 0;

}