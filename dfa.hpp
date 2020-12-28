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
		void setCsucsok(map<string, map<char, string>> value) { csucsok = value; }
		void hozzaadCsucs(string csucs, char c, string szomszedok);
		string szomszedok(string csucs);
		void hovalep(string csucs, char c);
		void hovalepCsucsbol(string csucs);
		void bejar(string kezdocsucs, string szo);
		bool ervenyesLepes(string csucs, char c);

		//szomszedok -> input: string, output: szomszédlista
		//éleken karakterek, másik csúcsba milyen karakterrel lehet eljutni
		//hovalep(int csucs,char c)
		//bejar(int kezdocsucs,string s) -- probal vegigmenni a stringgel, közben kiirja a konfigokat
		//kezdocsucs, elfogado allapotok, bemenetben meg lehessen adni

	};

#endif
