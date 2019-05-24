#ifndef GRAMATICA_H
#define GRAMATICA_h
#include "Simbol.h"

class Gramatica {
	vector<Simbol> productii;
	vector<char> litere;
	int dimCuvant;
	int nrProductii;

public:
	Gramatica(ifstream &);
	void generareGramatica(ofstream &);
	bool test(vector<char>);
	void addP(vector<char>&,Simbol);
	void addC(vector<char>&, char);
};



#endif // !GRAMATICA_H

