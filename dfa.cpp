#include <iostream>
#include <string>
#include "dfa.hpp"
#include "keyNotFoundException.hpp"
#include "nodeNotFoundException.hpp"

using namespace std;

void Dfa::kiir() {

	cout << "Az automata felepitese:" << endl << endl;
	map<string, map<char, string>> csucsok = getCsucsok();
	for (map<string, map<char, string>>::iterator ptr = csucsok.begin(); ptr != csucsok.end(); ptr++) {
		cout << ptr->first << " csucs:" << endl;
		for (map<char, string>::const_iterator eptr = ptr->second.begin(); eptr != ptr->second.end(); eptr++)
			cout << eptr->first << " -> " << eptr->second << endl;
	}
}

void Dfa::hozzaadCsucs(string csucs, char c, string szomszedok) {
	map<string, map<char, string>> csucsok = getCsucsok();
	csucsok[csucs].insert(std::make_pair(c, szomszedok));
	setCsucsok(csucsok);
}

string Dfa::szomszedok(string csucs) {

	map<string, map<char, string>> csucsok = getCsucsok();
	string szomszedok;

	map<string, map<char, string>>::const_iterator itr = csucsok.find(csucs);	 //megkeresi a megadott csúcsot
	if (itr == csucsok.end())													// ha nem találta meg
		throw nodeNotFoundException{ csucs };
	else {																		//ha megtalálta, akkor végigmegy a belsõ map-en is és keresi a kulcsot (karaktert)
		cout << endl << "A " << csucs << " csucs szomszedai: ";
		map<char, string > ::const_iterator ptr;
		for (itr = csucsok.begin(); itr != csucsok.end(); itr++) {
			for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
				if (itr->first == csucs)										//ha megtalálja, akkor kiszedi belõle az értéket (stringet)
					szomszedok += ptr->second + " ";
			}
		}
	}
	return szomszedok;
}

void Dfa::hovalep(string csucs, char c) { //megadott csucsbol a megadott karakterrel hova lehet lepni

	map<string, map<char, string>> csucsok = getCsucsok();
	map<string, map<char, string>>::const_iterator itr = csucsok.find(csucs);			//megkeresi a megadott csúcsot
	if (itr == csucsok.end())															// ha nem találta meg
		throw nodeNotFoundException{ csucs };
	else {
		map<char, string > ::const_iterator ptr;
		for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
			if (ptr->first == c) {													//ha megtalálja, akkor kiszedi belõle az értéket (stringet)
				cout << "A " << csucs << " csucsbol '" << c << "' karakterrel ebbe a csucsba erkezunk: " << ptr->second << endl;
				return;
			}
		}
		throw keyNotFoundException{ csucs, c };
	}
}

bool Dfa::ervenyesLepes(string csucs, char c) { //megadott csucsbol a megadott karakterrel lehet-e lepni
	map<string, map<char, string>> csucsok = getCsucsok();
	map<string, map<char, string>>::const_iterator itr = csucsok.find(csucs);			//megkeresi a megadott csúcsot
	if (itr == csucsok.end())															// ha nem találta meg
		return false;
	else {
		map<char, string > ::const_iterator ptr;
		for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
			if (ptr->first == c) {													//ha megtalálja, akkor kiszedi belõle az értéket (stringet)
				return true;
			}
		}
	}
	return false;
}

void Dfa::hovalepCsucsbol(string csucs) { // egy csucsbol milyen karakterrel hova lehet lepni
	cout << "A " << csucs << " csucsbol az alabbi karakterekkel az alabbi csucsokba lehet lepni:" << endl << endl;
	map<string, map<char, string>> csucsok = getCsucsok();
	string celCsucs;
	map<string, map<char, string>>::const_iterator itr = csucsok.find(csucs);			//megkeresi a megadott csúcsot
	if (itr == csucsok.end())															// ha nem találta meg
		throw nodeNotFoundException{ csucs };
	else {
		map<char, string > ::const_iterator ptr;
		for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++)
			cout << ptr->first << " -> " << ptr->second << endl;
		cout << endl;
	}
}

void Dfa::bejar(string kezdocsucs, string szo) { // rossz szó esete!!!

	map<string, map<char, string>> csucsok = getCsucsok();
	int i = szo.length();
	string tmp = szo;
	while (i > 0)
	{
		if (ervenyesLepes(kezdocsucs, tmp.at(0))) {

			cout << "(" << kezdocsucs << ", " << tmp << ")" << " -> ";

			kezdocsucs = csucsok[kezdocsucs][tmp.at(0)];
			tmp = tmp.erase(0, 1);
			i--;
		}
		else {
			cout << endl << "Nincs tovabblepesi lehetoseg, a(z) " << szo << " szot nem fogadja el az automata." << endl;
			return;
		}
		if (i == 0) {
			cout << "(" << kezdocsucs << ",e)" << endl;
		}
	}
}