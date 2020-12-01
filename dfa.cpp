#include <iostream>
#include <string>
#include "dfa.hpp"
#include "keyNotFoundException.hpp"
#include "nodeNotFoundException.hpp"

using namespace std;

void Dfa::kiir() {
	map<string, map<char, string>> csucsok = getCsucsok();
	for (map<string, map<char, string>>::iterator ptr = csucsok.begin(); ptr != csucsok.end(); ptr++) {
		cout << ptr->first << "\n";
		for (map<char, string>::const_iterator eptr = ptr->second.begin(); eptr != ptr->second.end(); eptr++)
			cout << eptr->first << " " << eptr->second << endl;
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

	map<string, map<char, string>>::const_iterator itr = csucsok.find(csucs);	 //megkeresi a megadott cs�csot
	if (itr == csucsok.end())													// ha nem tal�lta meg
		throw nodeNotFoundException{ csucs };
	else {																		//ha megtal�lta, akkor v�gigmegy a bels� map-en is �s keresi a kulcsot (karaktert)
		cout << "A " << csucs << "cs�cs szomsz�dai: ";
		map<char, string > ::const_iterator ptr;
		for (itr = csucsok.begin(); itr != csucsok.end(); itr++) {
			for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
				if (itr->first == csucs)										//ha megtal�lja, akkor kiszedi bel�le az �rt�ket (stringet)
					szomszedok += ptr->second + " ";
			}
		}
	}
	return szomszedok;
}

string Dfa::hovalep(string csucs, char c) {
	
	map<string, map<char, string>> csucsok = getCsucsok();
	string celCsucs;	
	map<string, map<char, string>>::const_iterator itr = csucsok.find(csucs);			//megkeresi a megadott cs�csot
	if (itr == csucsok.end())															// ha nem tal�lta meg
		throw nodeNotFoundException{ csucs };
	else {																				//ha megtal�lta, akkor v�gigmegy a bels� map-en is �s keresi a kulcsot (karaktert)
		map<char, string > ::const_iterator ptr;
		for (itr = csucsok.begin(); itr != csucsok.end(); itr++) {
			for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
				if(ptr->first == c)														//ha megtal�lja, akkor kiszedi bel�le az �rt�ket (stringet)
					celCsucs = ptr->second;
				else
					throw keyNotFoundException{ csucs };				
			}
		}
	}	
	return celCsucs;
}

void Dfa::bejar(string kezdocsucs, string szo) {
	
	map<string, map<char, string>> csucsok = getCsucsok();
	int i = szo.length();
	while (i >= 0)
	{
		cout << "(" << kezdocsucs << ", " << szo << ")";
		kezdocsucs = csucsok[kezdocsucs][szo.at(0)];
		szo = szo.erase(0, 1);
	}
}