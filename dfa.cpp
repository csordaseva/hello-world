#include <iostream>
#include <string>
#include "dfa.hpp"

using namespace std;

void kiir(map<string, map<char, string>> csucsok) {
	for (map<string, map<char, string>>::iterator ptr = csucsok.begin(); ptr != csucsok.end(); ptr++) {
		cout << ptr->first << "\n";
		for (map<char, string>::const_iterator eptr = ptr->second.begin(); eptr != ptr->second.end(); eptr++) {
			cout << eptr->first << " " << eptr->second << endl;
		}
	}
}

void Dfa::hozzaadCsucs(map<string, map<char, string>> csucsok, string csucs, char c, string szomszedok) {
	csucsok[csucs].insert(std::make_pair(c, szomszedok));
}

string Dfa::szomszedok( map<string, map<char, string>> &csucsok, string csucs) {
	string szomszedok;

	map<string, map<char, string>>::const_iterator itr = csucsok.find(csucs); //megkeresi a megadott csúcsot
	if (itr == csucsok.end()) {		// ha nem találta meg
		//handle the error
	}
	else {							//ha megtalálta, akkor végigmegy a belsõ map-en is és keresi a kulcsot (karaktert)
		cout << "A " << csucs << "csúcs szomszédai: ";
		map<char, string > ::const_iterator ptr;
		for (itr = csucsok.begin(); itr != csucsok.end(); itr++) {
			for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
				if (itr->first == csucs)				//ha megtalálja, akkor kiszedi belõle az értéket (stringet)
					szomszedok += ptr->second + " ";
			}
		}
	}

	return szomszedok;
}

string Dfa::hovalep(map<string, map<char, string>> csucsok, string csucs, char c) {
	string celCsucs;	
	map<string, map<char, string>>::const_iterator itr = csucsok.find(csucs); //megkeresi a megadott csúcsot
	if (itr == csucsok.end()) {		// ha nem találta meg
		//handle the error
	}
	else {							//ha megtalálta, akkor végigmegy a belsõ map-en is és keresi a kulcsot (karaktert)
		map<char, string > ::const_iterator ptr;
		for (itr = csucsok.begin(); itr != csucsok.end(); itr++) {
			for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
				if(ptr->first == c)				//ha megtalálja, akkor kiszedi belõle az értéket (stringet)
					celCsucs = ptr->second;
				else
				{
					//hibás karakter exception
				}
			}
		}
	}	
	return celCsucs;
}

void Dfa::bejar(map<string, map<char, string>> csucsok, string kezdocsucs, string szo) {
	int i = szo.length();
	while (i >= 0)
	{
		cout << "(" << kezdocsucs << ", " << szo << ")";
		kezdocsucs = csucsok[kezdocsucs][szo.at(0)];
		szo = szo.erase(0, 1);
	}
}