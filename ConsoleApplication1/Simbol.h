#ifndef SIMBOL_H
#define SIMBOL_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Simbol {
	int tip; // 0 neterminal , 1 terminal
	char nume;
	int cate;    //retin cate cuvinte am
	vector<char> cuvinte; //retin cuvintele
	vector<int> poz; //retine inceputul cuvintelor
	vector<int> dim; //retin dimensiunea corelat cu poz

public:
	Simbol();
	int getTip();
	void setTip(int);
	char getLitera();
	void setLitera(char);
	void generareCuvinte(ifstream &);
	char litera(int);
	int lungime(int);
	int marime();
	int getCate();
	int pozitie(int);

};

#endif