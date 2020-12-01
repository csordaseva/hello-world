#ifndef DFA_HPP
#define DFA_HPP

#include <map>
#include <string>

using namespace std;

class Dfa {

	private:
		map<string, map<char, string>> csucsok;
	public:
		void kiir();
		map<string, map<char, string>> getCsucsok() { return csucsok; }
		void setCsucsok(map<string, map<char, string>> value) { value = csucsok; }
		void hozzaadCsucs(string csucs, char c, string szomszedok);
		string szomszedok(string csucs);
		string hovalep(string csucs, char c);
		void bejar(string kezdocsucs, string szo);

		//szomszedok -> input: string, output: szomsz�dlista
		//�leken karakterek, m�sik cs�csba milyen karakterrel lehet eljutni
		//hovalep(int csucs,char c)
		//bejar(int kezdocsucs,string s) -- probal vegigmenni a stringgel, k�zben kiirja a konfigokat
		//kezdocsucs, elfogado allapotok, bemenetben meg lehessen adni

	};

#endif
