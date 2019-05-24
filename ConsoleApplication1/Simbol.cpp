#include "Simbol.h"
using namespace std;


Simbol::Simbol() {
	cate = 0;
}


int Simbol::getTip() {
	return tip;
}
void Simbol::setTip(int t) {
	tip = t;
}
char Simbol::getLitera() {
	return nume;
}
void Simbol::setLitera(char l) {
	nume = l;
}
void Simbol::generareCuvinte(ifstream &in) {
	in >> nume;
	if (nume > 95) {
		tip = 1;
	}
	else {
		tip = 0;
	}
	in.ignore(4);
	int contPoz = -1;
	int contDim = 0;
	cate = 1;
	poz.push_back(0);
	while ( 3 > 2 ) {
		
		if (in.peek() == EOF || in.peek() == '\n') {
			dim.push_back(contDim);
			break;
		}
		cuvinte.push_back(in.get());
		contDim++;
		contPoz++;
		if (in.peek() == '|') {
			cuvinte.push_back(' ');
			poz.push_back(contPoz+2);
			dim.push_back(contDim);
			contDim = 0;
			cate++;
			in.ignore(1);
			contPoz++;
		}
		
	}

}
char Simbol::litera(int p){
	return cuvinte[p];
}
int Simbol::lungime(int l) {
	return dim[l];
}
int Simbol::marime() {
	return cuvinte.size();
}
int Simbol::getCate() {
	return cate;
}
int Simbol::pozitie(int p) {
	return poz[p];
}
