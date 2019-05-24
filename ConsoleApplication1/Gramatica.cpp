#include "Gramatica.h"

Gramatica::Gramatica(ifstream &baga) {
	baga >> nrProductii;
	baga >> dimCuvant;
	for (int i = 0; i < nrProductii; i++) {
		productii.push_back(Simbol());
	}
	for (int i = 0; i < nrProductii; i++) {
		productii[i].generareCuvinte(baga);
		litere.push_back(productii[i].getLitera());
	} // am citit productiile si avem literele mari
}

void Gramatica::generareGramatica(ofstream &exit) {
	vector<char> mare;
	vector<char> mic;
	vector<char> tmp1;
	vector<char> panaLaSpatiu;
	for (int i = 0; i < productii[0].marime(); i++) {
		mare.push_back(productii[0].litera(i));
		exit << productii[0].litera(i);
	}//am urcat pentru prima productie gata i
	exit << endl;
 	while ( 3 > 2) {
		for (int i = 0; i < mare.size(); i++) {
			if (mare[i] == ' '|| i == mare.size() - 1) {
				if (i == mare.size() - 1) {
					panaLaSpatiu.push_back(mare[i]);
				}
				for (int j = 0; j < panaLaSpatiu.size(); j++) {
					if (panaLaSpatiu[j] < 95) {
						int aici;
						for (int k = 0; k < nrProductii; k++) {
							if (litere[k] == panaLaSpatiu[j]) {
								aici = k;
							}
						}//am indetificat litera si productia gata k

						addP(mic, productii[aici]);
					}
					else {
						addC(mic, panaLaSpatiu[j]);
					}
				}
				for (int o = 0; o < mic.size(); o++) {
					tmp1.push_back(mic[o]);
				}
				tmp1.push_back(' ');
				mic.clear();
				panaLaSpatiu.clear();
			}
			else {
				panaLaSpatiu.push_back(mare[i]);
			}
		}//parcurg pe mare
		mare.clear();
		for (int i = 0; i < tmp1.size()-1; i++) {
			exit << tmp1[i];
			mare.push_back(tmp1[i]);
		}
		mic.clear();
		panaLaSpatiu.clear();
		tmp1.clear();
		dimCuvant--;
		exit << endl;
		if (test(mare) == false) {
			break;
		}
	}//end while
}
bool Gramatica::test(vector<char> a) {
	vector<char> cuvant;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == ' ' || i == a.size()-1) {
			int are = 0;
			for (int j = 0; j < cuvant.size(); j++) {
				if (cuvant[j] < 95) {
					are++;
				}
			}
			if (are > 0) {
				int tmp = cuvant.size() - are;
				if (tmp >= dimCuvant) {
					return false;
				}
			}
			cuvant.clear();
		}
		else {
			cuvant.push_back(a[i]);
		}
	}
	return true;
}
void Gramatica::addP(vector<char> &unde, Simbol s) {
	vector<char> tmp;
	bool spatii = false;
	for (int i = 0; i < unde.size(); i++) {
		if (unde[i] == ' ') {
			spatii = true;
		}
	}
	if (spatii == false) {
		for (int i = 0; i < s.getCate(); i++) {
			for (int j = 0; j < unde.size(); j++) {
				tmp.push_back(unde[j]);
			}
			if (i + 1 != s.getCate()) {
				for (int j = s.pozitie(i); j < s.pozitie(i + 1) - 1; j++) {
					tmp.push_back(s.litera(j));
				}
				tmp.push_back(' ');
			}
			else {
				for (int j = s.pozitie(i); j < s.marime(); j++) {
					tmp.push_back(s.litera(j));
				}
			}
		}
	}
	else {
		for (int cont = 0; cont < s.getCate(); cont++) {
			for (int i = 0; i < unde.size(); i++) {
				tmp.push_back(unde[i]);
			}
			for (int j = 0; j < tmp.size(); j++) {
				if (tmp[j] == ' ') {
					for (int k = s.pozitie(cont); k < s.marime(); k++) {
						tmp.insert(tmp.begin() + j, s.litera(k));
						j++;
					}
				}
				else if (j == tmp.size() - 1){
					for (int k = s.pozitie(cont); k < s.marime(); k++) {
						tmp.push_back(s.litera(k));
						j++;
					}
				}
			}
			if (cont != s.getCate() - 1) {
				tmp.push_back(' ');
			}
		}
	}
	unde.clear();
	for (int i = 0; i < tmp.size(); i++) {
		unde.push_back(tmp[i]);
	}
}
void Gramatica::addC(vector<char> &unde, char cine) {
	if (unde.size() == 0) {
		unde.push_back(cine);
	}
	else {
		for (int i = 0; i < unde.size(); i++) {
			if (unde[i] == ' ') {
				unde.insert(unde.begin() + i, cine);
				i++;
			}
		}
		unde.push_back(cine);
	}
}