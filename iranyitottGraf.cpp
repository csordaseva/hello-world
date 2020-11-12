//feladat: iranyitott graf;felhasznalo megad egy csucsot, kiirja, hogy onnan hova vezetnek elek

#include <iostream>
#include <clocale>
#include <vector>
#include <string>
#include <sstream>

#define MAX 30

typedef struct pont {
	int sorszam;
	std::vector<int> szomszedok;
} Pont;

typedef struct graf {
	Pont* pontok[MAX];
} Graf;

void feltolt(Graf* graf, int db);
bool bennevan(Graf* graf, int szam, int db);
void szomszedok(Graf* graf, int db, int csucs);
bool csucsEll(int csucs, int n);
void feltoltElek(Graf* graf, int db);
bool szamEll(std::string input, int db);

int main()
{
	std::setlocale(LC_ALL, "hun");

	Graf* g1 = new Graf;

	int n = 0;
	std::string db = "";
	std::cout << "Adja meg a gr�f cs�cspontjainak sz�m�t: ";
	do
	{
		std::getline(std::cin, db);
	} while (!szamEll(db,MAX));
	n = stoi(db);

	feltolt(g1, n);

	feltoltElek(g1, n);

	int csucs = 0;
	std::string s_csucs = "";
	std::cout << "Adjon meg egy cs�csot a(z) [1," << n << "] intervallumon:\n";
	do
	{
		std::getline(std::cin, s_csucs);
		csucs = stoi(s_csucs);
	} while (s_csucs != "" & !csucsEll(csucs, n));

	szomszedok(g1, n, csucs);

	return 0;
}

void szomszedok(Graf* graf, int db, int csucs) {
	if (!bennevan(graf, csucs, db))
		std::cout << "A megadott sz�m� cs�cs (" << csucs << ") nem szerepel a gr�fban." << std::endl;
	else
	{
		std::cout << "A megadott sz�m� cs�cs (" << csucs << ") szomsz�dai:" << std::endl;
		for (int i = 0; i < db; i++)
		{
			if (graf->pontok[i]->sorszam == csucs)
			{
				std::vector<int> it = graf->pontok[i]->szomszedok;
				if (it.empty())
					std::cout << "Ebb�l a cs�csb�l nem megy kifel� �l." << std::endl;
				else
					for (int j = 0; j < it.size(); j++) {
						if (j == it.size()-1)
							std::cout << it.at(j) << std::endl;						
						else
							std::cout << it.at(j) << ", ";
					}
			}
		}
	}
}

bool bennevan(Graf* graf, int szam, int db) {
	for (int i = 0; i < db; i++)
	{
		if (graf->pontok[i]->sorszam == szam)
			return true;
	}
	return false;
}

void feltolt(Graf* graf, int db) {
	for (int i = 0; i < db; i++) {
		graf->pontok[i] = new Pont;
		graf->pontok[i]->sorszam = i + 1;
	}

	std::cout << "A gr�fnak " << db << " cs�cspontja van." << std::endl;
}

bool csucsEll(int csucs, int n) {

	std::string szam = std::to_string(csucs);
	if (!szamEll(szam, n))
	{
		std::cout << "Hiba. Nem sz�m." << std::endl;
		return false;
	}
	else {
		if (csucs > 0 && csucs <= n)
			return true;
		else
		{
			std::cout << "Hiba. A megadott cs�cs nem tal�lhat� a gr�fban." << std::endl;
			return false;
		}
	}
}

void feltoltElek(Graf* graf, int db) {
	int szomszed = 0;
	std::string szomsz = "";
	bool exit = false;
	for (int i = 0; i < db; i++)
	{
		std::cout << "A(z) " << i + 1 << ". csom�pont szomsz�dai (Enter: bevitel v�ge):\n";
		do
		{
			exit = false;
			std::getline(std::cin, szomsz);
			if (szamEll(szomsz, db) && szomsz != "") {
				szomszed = stoi(szomsz);
				graf->pontok[i]->szomszedok.push_back(szomszed);				
			}
			else if (szomsz == "")
				exit = true;
		} while (!exit || !csucsEll(szomszed, db));
	}
}

bool szamEll(std::string input, int db) {
	for (int i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]) && input[i] != '-')
		{
			std::cout << "Hiba. Nem sz�m." << std::endl;
			return false;
		}
	}
	if (input != "")
	{
		int szam = stoi(input);
		if (szam <= 0)
		{
			std::cout << "A megadott sz�m pozit�v lehet csak." << std::endl;
			return false;
		}
		if (szam > db)
		{
			std::cout << "Hiba. Nincs ilyen sorsz�m� pont a gr�fban." << std::endl;
			return false;
		}
	}	
	return true;
}
