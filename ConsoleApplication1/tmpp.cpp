/*vector<char> mare;
vector<char> mic;
vector<char> tmp1;
vector<char> tmp2;
vector<char> panaLaSpatiu;
for (int i = 0; i < productii[0].marime(); i++) {
	mare.push_back(productii[0].litera(i));
	exit << productii[0].litera(i);
}//am urcat pentru prima productie gata i
exit << endl;
while (dimCuvant > 0) {          //test(mare) == true) {
	for (int i = 0; i < mare.size(); i++) {
		if (mare[i] == ' ' || i == mare.size() - 1) {
			for (int j = 0; j < panaLaSpatiu.size(); j++) {
				if (panaLaSpatiu[j] < 95) {
					int aici;
					for (int k = 0; k < nrProductii; k++) {
						if (litere[k] == panaLaSpatiu[j]) {
							aici = k;
						}
					}//am indetificat litera si productia gata k
					for (int l = 0; l < productii[aici].getCate(); l++) {
						if (l == productii[aici].getCate() - 1) {
							for (int k = 0; k < mic.size(); k++) {
								tmp1.push_back(mic[k]);
							}//am pus ce era in mic
							for (int g = productii[aici].pozitie(l); g < productii[aici].marime(); g++) {
								tmp1.push_back(productii[aici].litera(g));
							}
						}
						else {
							for (int k = 0; k < mic.size(); k++) {
								tmp1.push_back(mic[k]);
							}//am pus ce era in mic
							for (int g = productii[aici].pozitie(l); g < productii[aici].pozitie(l + 1) - 1; g++) {
								tmp1.push_back(productii[aici].litera(g));
							}
							tmp1.push_back(' ');
						}
					}//aici am pus ce era in restul 
					mic.clear();
				}
				else {
					mic.push_back(panaLaSpatiu[j]);
					if (j + 1 == panaLaSpatiu.size()) {
						for (int g = 0; g < tmp1.size(); g++) {
							if (tmp1[g] == ' ' || g + 1 == tmp1.size()) {
								int undeInserez = g;
								for (int k = 0; k < mic.size(); k++) {
									tmp1.insert(tmp1.begin() + undeInserez, mic[k]);
									undeInserez++;
									g++;
								}
							}
						}
					}//end if
				}
			}
			for (int o = 0; o < tmp1.size(); o++) {
				tmp2.push_back(tmp1[o]);
			}
			tmp2.push_back(' ');
			tmp1.clear();
			panaLaSpatiu.clear();
		}
		else {
			panaLaSpatiu.push_back(mare[i]);
		}
	}//parcurg pe mare
	mare.clear();
	for (int i = 0; i < tmp2.size(); i++) {
		exit << tmp2[i];
		mare.push_back(tmp2[i]);
	}
	mic.clear();
	panaLaSpatiu.clear();
	tmp1.clear();
	tmp2.clear();
	dimCuvant--;
	exit << endl;
}//end while
*/