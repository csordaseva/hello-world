#ifndef DFA_HPP
#define DFA_HPP

#include <map>
#include <string>

using namespace std;

class Dfa {

	private:
		map<string, map<char, string>> csucsok;
	public:
		Dfa() {};
		map<string, map<char, string>> getCsucsok() { return csucsok; }
		void hozzaadCsucs(map<string, map<char, string>> csucsok, string csucs, char c, string szomszedok);
		string szomszedok(map<string, map<char, string>>& csucsok, string csucs);
		string hovalep(map<string, map<char, string>> csucsok, string csucs, char c);
		void bejar(map<string, map<char, string>> csucsok, string kezdocsucs, string szo);

		//szomszedok -> input: string, output: szomszédlista
		//éleken karakterek, másik csúcsba milyen karakterrel lehet eljutni
		//hovalep(int csucs,char c)
		//bejar(int kezdocsucs,string s) -- probal vegigmenni a stringgel, közben kiirja a konfigokat
		//kezdocsucs, elfogado allapotok, bemenetben meg lehessen adni

	};

#endif
