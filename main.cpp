#include <iostream>
#include "dfa.hpp"
#include "keyNotFoundException.hpp"
#include "nodeNotFoundException.hpp"


int main()
{
	Dfa dfa;

	dfa.hozzaadCsucs("q0", 'a',"q1");
	dfa.hozzaadCsucs("q0", 'b', "q2");
	dfa.hozzaadCsucs("q1", 'a', "q4");
	dfa.hozzaadCsucs("q1", 'b', "q3");
	dfa.hozzaadCsucs("q1", 'e', "q1");
	dfa.hozzaadCsucs("q2", 'b', "q3");
	dfa.hozzaadCsucs("q3", 'a', "q4");
	dfa.hozzaadCsucs("q3", 'b', "q5");
	dfa.hozzaadCsucs("q4", 'b', "q5");

	dfa.kiir();

	cout << endl;

	try
	{
		dfa.hovalepCsucsbol("q0");
		dfa.hovalepCsucsbol("q1");
		dfa.hovalepCsucsbol("q2");
		dfa.hovalepCsucsbol("q3");
		dfa.hovalepCsucsbol("q4");
	}
	catch (nodeNotFoundException ex)
	{
		cout << endl << "Exception: nem talalhato a megadott csucs: " << ex.msg << endl;
	}
	

	string szomszedok = dfa.szomszedok("q0");
	cout << szomszedok;
	szomszedok = dfa.szomszedok("q1");
	cout << szomszedok;
	szomszedok = dfa.szomszedok("q2");
	cout << szomszedok;
	szomszedok = dfa.szomszedok("q3");
	cout << szomszedok;
	szomszedok = dfa.szomszedok("q4");
	cout << szomszedok;

	string hovalep;
	try
	{
		cout << endl << endl << "Adott csucsbol adott karakterrel hova lepunk:" << endl << endl;

		dfa.hovalep("q0", 'a');
		dfa.hovalep("q0", 'b');
		dfa.hovalep("q1", 'a');
		dfa.hovalep("q1", 'b');
		dfa.hovalep("q1", 'e');
		dfa.hovalep("q2", 'b');
		dfa.hovalep("q3", 'a');
		dfa.hovalep("q3", 'b');
		dfa.hovalep("q4", 'b');
		dfa.hovalep("q4", 'a');
	}
	catch (nodeNotFoundException ex)
	{
		cout << endl << "Exception: nem talalhato a megadott csucs: " << ex.msg << endl;
	}
	catch (keyNotFoundException ex) {
		cout << endl << "Exception: nem talalhato a "<< ex.node << " csucs kulcsa: " <<ex.key << endl;
	}

	cout << endl << "Megadott szo bejarasa, konfiguraciok kiirasa:" << endl << endl;

	dfa.bejar("q0", "bbab");

	return 0;
}
